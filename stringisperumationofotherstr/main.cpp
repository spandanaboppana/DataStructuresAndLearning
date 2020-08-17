#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


bool isPermutation(string str1, string str2) {

    if(str1.length() != str2.length()){
        return false;
    }
    unordered_map<char, int> my_map;

    for(int i=0; i<str1.length();i++){
        if(my_map.find(str1[i]) != my_map.end()){
            my_map[str1[i]]++;
        } else {
            my_map[str1[i]] = 1;
        }
    }

    for(int i=0; i<str2.length();i++) {
        if(my_map.find(str2[i]) == my_map.end()){
            return false;
        } else {
            my_map[str2[i]]--;
            if(my_map[str2[i]] == 0) {
                my_map.erase(str2[i]);
            }
        }
    }

    if(my_map.empty()){
        return true;
    } else {
        return false;
    }

}
int main() {
    bool result = isPermutation("aa", "ab");
    cout<<result;
    return 0;
}