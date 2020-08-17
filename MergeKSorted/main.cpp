#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int val;
    int arrIndx;
    int Indx;
};

struct compareGreater{
    bool operator()(Node a, Node b){
        return a.val > b.val;
    }
};

struct compareLess{
    bool operator()(Node a, Node b){
        return a.val < b.val;
    }
};

bool findSortOrder(vector<vector<int>> arr){
   int arrSize = arr.size()-1;
   for(int i=0; i<=arrSize; i++){
       if(arr[i].size() >= 2){
           if(arr[i][0] < arr[i][arr[i].size()-1]){
               return true;
           }
           else if(arr[i][0] > arr[i][arr[i].size()-1]){
               return false;
           }
       }
   }
}
template <typename T>
void MergeKSortedArrays(vector<vector<int>> &arr, vector<int> &result, T my_heap){
    int arrSize = arr.size();
    for(int i=0; i<arrSize; i++){
      if(arr[i].size()){
          my_heap.push({arr[i][0], i, 0});
      }
    }

    while(my_heap.size()) {
        Node curr = my_heap.top();
        result.push_back(curr.val);
        my_heap.pop();
        curr.Indx++;
        if(curr.Indx < arr[curr.arrIndx].size()){
            curr.val = arr[curr.arrIndx][curr.Indx];
            my_heap.push(curr);
        }
    }
}

int main() {

    vector<vector<int>> arr = {{1,3,5,7}, {2,4,6,8}, {0,9,10,11}};
    vector<int> result;
    priority_queue<Node, vector<Node>, compareGreater> min_heap;
    priority_queue<Node, vector<Node>, compareLess> max_heap;
    if(findSortOrder(arr)){
         MergeKSortedArrays(arr, result, min_heap);
    } else {
         MergeKSortedArrays(arr, result, max_heap);
    }
    for(int i=0; i< result.size(); i++){
        cout<< result[i];
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}