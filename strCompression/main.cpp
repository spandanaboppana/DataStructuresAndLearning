#include <iostream>
#include <string>
#include <vector>

using namespace std;

string strCompression(string str){
    string result;
    int last = 0;
    int count = 0;
    for( int i=1 ; i<=str.length()-1; i++){
        if(str[i] == str[last]){
            count++;
            continue;
        } else {
            count = 0;
            last = i;
        }
        result = result + str[last];
        result = result + to_string(count+1);
    }
    return result;
}

int main() {
    string result = strCompression("aabcccccaaa");
    cout<<result;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}