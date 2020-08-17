#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int> &arr, int low, int high, int pivot_val){
    int low_val = low;
    int high_val = low;

    while(high_val < high) {
        if(arr[high_val] > pivot_val) {
            high_val++;
        } else if (arr[high_val] < pivot_val) {
            swap (arr[high_val], arr[low_val]);
            low_val++;
            high_val++;
        } else if (arr[high_val] == pivot_val) {
            swap (arr[high_val], arr[high]);
        }
    }
    swap(arr[low_val], arr[high]);
    return low_val;
}

void QuickSort(vector<int> &nuts, vector<int> &bolts, int low, int high) {
    if(low < high) {

        // Choose random integer of nuts array for bolts partition.
        // Here partition is done for both nuts and bolts array

         int pivot = Partition(nuts, low, high, bolts[high]);
         Partition(bolts, low, high, nuts[pivot]);

        // Recur for [low...pivot-1] & [pivot+1...high] for nuts and
        // bolts array.
        QuickSort(nuts,bolts, low, pivot-1);
        QuickSort(nuts,bolts, pivot+1, high);
    }

}

/*
 * Complete the solve function below.
 */
vector<string> solve(vector<int> nuts, vector<int> bolts) {
    /*
     * Write your code here.
     */
    int low = 0;
    int high = nuts.size()-1;
    vector<string> result;
    QuickSort(nuts,bolts,low,high);

    for(int i=0; i<high;i++){
        result.push_back(to_string(nuts[i]) + "" + to_string(bolts[i]));
    }

    return result;

}

int main() {
    vector<int>nuts{4, 32, 5, 7};
    vector<int>bolts{32, 7, 5, 4};
    solve(nuts, bolts);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}