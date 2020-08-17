#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long find_integer(vector<long> &arr) {
int size = (int)(pow(2, 32)/8);
vector<int> bytes_array(size,0);

for(int i=0; i<arr.size(); i++) {
    int byte_index = (int) arr[i] / 8;
    int bitIndex = (int) byte_index % 8;

    bytes_array[byte_index] |= 1 << bitIndex;
}

for(int byte_index = 0; byte_index < size; byte_index++) {
    for(int bitIndex = 0; bitIndex < 8; bitIndex++) {
        if((bytes_array[byte_index] & (1<<bitIndex)) == 0) {
            return byte_index*8L + bitIndex;
        }
    }
}

}

int main() {
    vector<long> arr{0, 1, 2, 3};
    long a = find_integer(arr);
    cout<<a;
    return 0;
}