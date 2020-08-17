#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &nums, int low, int high, int pivot_indx) {

    int pivot = nums[pivot_indx];

    int low_val = low;
    swap (nums[low], nums[pivot]);
    for(int high_val = low+1; high_val <= high; high_val++){
        if (nums[high_val] < pivot){
            low_val++;
            swap(nums[low_val], nums[high_val]);
        }
    }
    swap (nums[low], nums[low_val]);
    return low_val;
}

int quickselect(vector<int> &nums, int low, int high, int k_smallest) {
    if(low == high){
        return nums[low];
    }
    int pivot_indx =  rand() % high + low;
    int indx = partition(nums,low, high, pivot_indx);

    if (indx == k_smallest) {
        return nums[k_smallest];
    } else if (k_smallest < indx) {
        return quickselect(nums, low, indx-1, k_smallest);
    } else
        return quickselect(nums, indx+1, high, k_smallest);
}

int findKthLargest(vector<int>& nums, int k) {
    int high = nums.size();
    return quickselect(nums,0,high-1,high-k);
}
int main() {
    vector<int> nums {2,1};
   cout<< findKthLargest(nums,1);
    return 0;
}