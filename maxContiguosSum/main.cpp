#include <iostream>
#include <vector>
using namespace std;

int maxContiguousSum(vector<int> input) {
    int result = INT_MIN;
    int curr_min = 0;
    for(int i =0; i< input.size(); i++){

        if( i == 0){
            curr_min = input[i];
        } else {
            curr_min = max(input[i], curr_min + input[i]);
        }
        result = max(result, curr_min);
    }
    return result;

    return 0;
}
int main()
{
    //
   assert(maxContiguousSum({-2,8,-9,15,-15,52,-10,20}) == 62);
   assert(maxContiguousSum({-2,-8,19,-15,15,2,-10,20}) == 31);
   return 0;
}
