#include <iostream>
using namespace std;

string getString(string &str) {
    int n=str.length(), count=0;
    string result="";
    for(int i=n-1; i>=0; i--) {
        char ch=str[i];
        if(ch=='#')
            count++;
        else {
            if(count>0)
                count--;
            else {
                result+=ch;
            }
        }
    }
    return result;
}

bool backspaceCompare(string S, string T) {
    return getString(S)==getString(T);
}
int main() {
    backspaceCompare("ab#c", "ac#c");
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}