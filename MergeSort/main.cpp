#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int >&arr, int start, int mid, int end){

    vector<int> left_arr(mid-start);
    for(int i=0; i<mid-start; i++){
        left_arr[i] = arr[i];
    }

    vector<int> right_arr(end-mid);
    for(int j= 0; j<= end-mid; j++){
        right_arr[j] = arr[mid+j];
    }
    int i =0, j= 0, k =0;
    while( i< left_arr.size() && j < right_arr.size()){
        if(left_arr[i] <= right_arr[j]){
            arr[k] = left_arr[i];
            i++;
        } else if(left_arr[i] > right_arr[j]){
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while(i < left_arr.size() ){
       arr[k] = left_arr[i];
       k++;
       i++;
    }
    while(j < right_arr.size()){
        arr[j] = right_arr[j];
        j++;
        k++;
    }
}


void split(vector<int> &arr, int start, int end){
    vector<int> aux(end-start+1, 0);
    if(start < end) {
        int mid = (start + end) / 2;

        //sort first and second halves of the array
        split(arr, start, mid);
        split(arr, mid + 1, end);

       merge(arr, start, mid, end);

    }

}
vector<int> merge_sort(vector<int> &arr) {
    int start = 0;
    int end = arr.size()-1;
    split(arr, start, end);

}
int main() {
    vector<int> arr{1, 7, 5, 3};

    merge_sort(arr);

    for(int i =0; i<arr.size() ;i++){
        cout<<arr[i];
    }

    return 0;
}