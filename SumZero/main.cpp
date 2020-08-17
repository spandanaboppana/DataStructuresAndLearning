#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> sumZero(vector<long> &arr) {

    unordered_map<long,int> my_map;
    int sum = 0;
    vector<int> result;

    for(int i=0; i<arr.size(); i++){
        sum = sum + arr[i];
        if(i == 0){
            my_map[arr[i]] = 0;
        }
        else {
            int index = arr[i]+sum;
            if(my_map.find(index) == my_map.end()){
                my_map[index] = i;
            } else {
                result.push_back(my_map[index] + 1);
                result.push_back(i);
            }
        }
    }
    return result;

}

int main() {
    vector<long> arr{5, 1, 2, -3, 7, -4};
    vector<int> result;

    result = sumZero(arr);

    for(int i =0; i<result.size();i++){
        cout<<result[i]<< " ";
    }
    return 0;
}