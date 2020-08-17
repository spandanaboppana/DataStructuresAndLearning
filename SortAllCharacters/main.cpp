#include <iostream>
#include <vector>
using namespace std;



vector<int> SortAllchars(vector<int> &arr){
    vector<int> freq(128,0);

    for(char c : arr){
        freq[c]++;
    }
    arr.erase(arr.begin(), arr.end());

    for(int i=0; i<128; i++){
        for(int j=0; j<freq[i];j++){
            arr.push_back(char(i));
        }
    }
    return arr;
}

int main() {
    vector<int> arr = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
    SortAllchars(arr);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}