#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;
struct Point{
    int indx;
    double dist;
};

int quickselect(vector<Point> &result, int left, int right){
    int pivot_ind = rand() % right;
    double pivot_val = result[pivot_ind].dist;
    swap(result[left], result[pivot_val]);
    int smaller = left;

    for(int bigger=left+1; bigger<right; bigger++){
        if(result[bigger].dist < pivot_val){
            smaller++;
            swap(result[smaller], result[bigger]);
        }
    }
    swap(result[smaller], result[left]);
    return smaller;
}

void topk(vector<Point>&result, int k) {
   int left = 0;
   int right = result.size();
   while(left<right){

       int part = quickselect(result, left, right);
       if(part == k){
           return;
       } else if(part < k){
           left = part+1;
       } else {
           right = part-1;
       }
   }
}

vector<vector<int>> nearest_neighbours(int p_x, int p_y, int k, vector<vector<int>> &points) {
    vector<Point> result;
    vector<vector<int>> final_op;
    for(int i=0; i<points.size(); i++){
        Point pt;
        pt.indx = i;
        pt.dist = sqrt((p_x-points[i][0])*1l*(p_x-points[i][0]) + (p_y-points[i][1])*1l*(p_y-points[i][1]));
        result.push_back(pt);
    }
    topk(result, k);
   for(int i=0; i<k; i++){
        vector<int> neigh;

        int each_neigh_size = points[result[i].indx].size();
        for(int j = 0; j< each_neigh_size; j++){
            neigh.push_back(points[result[i].indx][j]);
        }

        final_op.push_back(neigh);
    }
    return final_op;
}

int main() {
    int p_x = 0;
    int p_y = 0;
    int k = 2;
    vector<vector<int>> n_points{{1,1},{0,1},{1,0}};
    vector<vector<int>> result;
    result = nearest_neighbours(p_x, p_y, k, n_points);
    for(int i=0; i<result.size(); i++){
        cout<<result[i][1]<<endl;
    }
    return 0;
}