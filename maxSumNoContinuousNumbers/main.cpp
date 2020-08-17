#include <iostream>
#include <vector>
using namespace std;
/*
 * Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array.
 * So
 *  3 2 7 10    should return 13 (sum of 3 and 10) or
 *  3 2 5 10 7  should return 15 (sum of 3, 5 and 7).
    Examples :

    Input : arr[] = {5, 5, 10, 100, 10, 5}
    Output : 110

    Input : arr[] = {1, 2, 3}
    Output : 4

    Input : arr[] = {1, 20, 3}
    Output : 20
 */



int maxSumNoTwoContiguousNumbersUtil(vector<int> input, int index){

    if(index < 0){
        return -1;
    }

    if(index == 0){
        return input[index];
    }

    if(index == 1){
        return max(input[0], input[1]);
    }

    return max((input[index] + maxSumNoTwoContiguousNumbersUtil(input, index-2)) , maxSumNoTwoContiguousNumbersUtil(input, index-1));
}

int Util_Dp(vector<int> input) {
    vector<int> dp(input.size());
    dp[0] = input[0];
    dp[1] = max(input[0], input[1]);
    for(int i=2; i<dp.size(); i++){
        dp[i] = max(input[i] + dp[i-2], dp[i-1]);
    }
    return dp[input.size()-1];
}

int maxSumNoTwoContiguousNumbers(vector<int> input) {
    int result;
  //result =  maxSumNoTwoContiguousNumbersUtil(input, input.size()-1);
    result = Util_Dp(input);
    return result;
}

/*
 * Given a sequence of positive numbers, find the maximum sum that can be formed which has no three consecutive elements present.
    Examples :

    Input: arr[] = {1, 2, 3}
    Output: 5
    We can't take three of them, so answer is
    2 + 3 = 5

    Input: arr[] = {3000, 2000, 1000, 3, 10}
    Output: 5013
    3000 + 2000 + 3 + 10 = 5013

    Input: arr[] = {100, 1000, 100, 1000, 1}
    Output: 2101
    100 + 1000 + 1000 + 1 = 2101

    Input: arr[] = {1, 1, 1, 1, 1}
    Output: 4

    Input: arr[] = {1, 2, 3, 4, 5, 6, 7, 8}
    Output: 27
 */

int Util_Dp_Three(vector<int> input){
   vector<int> dp(input.size());

   dp[0] = input[0];
   dp[1] = input[0] + input[1];
   dp[2] = max(max(input[0]+ input[1], input[0]+input[2]), input[1] + input[2]);
   for(int i =3 ; i < input.size(); i++) {
       dp[i] = max(max(input[i] + input[i - 1] + dp[i - 3], input[i] + dp[i - 2]), dp[i - 1]);
   }
   return dp[input.size()-1];
}

int Util(vector<int> input, int index) {

    if (index < 0) {
        return 0;
    }

    if (index == 0) {
        return input[index];
    }

    if (index == 1) {
        return input[0] + input[1];
    }

    return max(max(input[index] + input[index-1] + Util(input, index-3), input[index] + Util(input, index-2)), Util(input, index-1));

}
int maxSumNoThreeContiguousNumbers(vector<int> input) {

   //return Util(input, input.size()-1);
   return Util_Dp_Three(input);

}
int main()
{
    assert(maxSumNoTwoContiguousNumbers({3, 2, 7, 10}) == 13);
    assert(maxSumNoTwoContiguousNumbers({3, 2, 7, 10, 7}) == 17);
    assert(maxSumNoTwoContiguousNumbers({5, 5, 10, 100, 10, 5}) == 110);
    assert(maxSumNoTwoContiguousNumbers({1, 2, 3}) == 4);
    assert(maxSumNoTwoContiguousNumbers({1, 20, 3}) == 20);

    assert(maxSumNoThreeContiguousNumbers({1, 2, 3}) == 5);
    assert(maxSumNoThreeContiguousNumbers({3000, 2000, 1000, 3, 10}) == 5013);
    assert(maxSumNoThreeContiguousNumbers({100, 1000, 100, 1000, 1}) == 2101);
    assert(maxSumNoThreeContiguousNumbers({1, 1, 1, 1, 1}) == 4);
    assert(maxSumNoThreeContiguousNumbers({1, 2, 3, 4, 5, 6, 7, 8}) == 27);

    return 0;
}
