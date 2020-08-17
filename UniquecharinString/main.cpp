#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

char firstUniqChar(string s) {
    int n = s[0] - 'a';

    for(int i=1; i<s.size(); i++){

        int ithNumber = s[i] - 'a';
        cout << "Xoring " << n << " ^ " << ithNumber << endl;
        n = (n ^ ithNumber);
    }
    if( n == 0) {
        return ' ';
    } else {
        return char(n + 'a');
    }
}


int main() {

    char str = firstUniqChar("aabbcd");
    cout << str;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}