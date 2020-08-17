#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

 void letterCasePermutation(string & input, int pos, vector<string> &result) {
     if (pos == input.length()) {
         result.push_back(input);
     } else {
         if (isdigit(input[pos])) {
             letterCasePermutation(input, pos + 1, result);
         } else {
             input[pos] = tolower(input[pos]);
             letterCasePermutation(input, pos + 1, result);
             input[pos] = toupper(input[pos]);
             letterCasePermutation(input, pos + 1, result);
         }
     }
 }
int main() {
    string input = "a1b2";
    vector<string> result;
    letterCasePermutation(input, 0, result);
    for(int i =0; i<result.size(); i++) {
        cout<<result[i];
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}