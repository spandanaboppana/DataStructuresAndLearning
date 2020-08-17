#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> Topk(vector<int> arr, int k){
    priority_queue <int, vector<int>, greater<int> > min_heap;
    unordered_set<int> min_heap_set;
   vector<int> result;
   int count = 0;
   int i = 0;
   for(int i = 0; i<arr.size(); i++){
       if(min_heap_set.find(arr[i]) != min_heap_set.end()){
           continue;
       }
       if(min_heap.size() < k){
           min_heap.push(arr[i]);
           min_heap_set.insert(arr[i]);
       } else {
           if(min_heap.top() < arr[i]){
               int top = min_heap.top();
               min_heap.pop();
               min_heap_set.erase(top);
               min_heap.push(arr[i]);
               min_heap_set.insert(arr[i]);
           }
       }
   }

    for (auto i = min_heap_set.begin(); i != min_heap_set.end(); ++i) {
        result.push_back(*i);
    }
return result;
}
int main() {
    vector<int> arr{5,
            6,
            1,
            4,
            1,
            8,
            2,
            4,
            1,
            7,
            9,
            3,
            2,
            1,
            2};
    int k = 2;
    vector<int> result;
    result = Topk(arr, k);
    for(int i =0; i<result.size(); i++){
        cout<< result[i];
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}