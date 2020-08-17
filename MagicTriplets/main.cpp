#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<string> findZeroSum(vector<int> arr){
    unordered_set<string> myset;
    sort(arr.begin(), arr.end());

    for(int i=0; i<arr.size(); i++){
        int curr_ele = arr[i];
        int val_needed = -curr_ele;
        int left = i+1, right = arr.size()-1;
        while(left < right){
            int sum = arr[left] + arr[right];
            if(sum == val_needed){
                myset.insert(curr_ele + "," + arr[left] + "," + arr[right]);
                left++; // right-- also would work
            } else if(sum > val_needed){
                right--;
            } else {
                left++;
            }
        }
    }

}
int main() {
    vector<int> arr{10, 3, -4, 1, -6, 9};
    vector<string> result;
    void findZeroSum(arr, result);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}