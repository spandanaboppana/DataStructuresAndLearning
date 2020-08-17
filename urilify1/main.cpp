#include <string>
#include <iostream>

using namespace std;

string urilify(string input, int len){
    int i = input.length()-1;
     len = len-1;
    while(len>=0 || i>=0){
        if(input[len] != ' '){
            swap(input[len], input[i]);
            len--;
            i--;
        } else {
            int j = len;
            input[len++] = '%';
            input[len++] = '2';
            input[len] = '0';

        }
    }
    return input;
}

int main() {
    string input = "Mr John Smith    ";
    string result =  urilify(input ,13);
    cout<<result;


    return 0;
}