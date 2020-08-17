#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkReplace(string str1, string str2){
    int count = 0;
    for(int i =0; i<str1.length(); i++){
        if(str1[i] == str2[i]){
            continue;
        } else {
            count = 1;
        }
    }
    if(count <= 1) {
        return true;
    } else {
        return false;
    }
}

bool checkInsert(string smallstr, string bigstr) {

    int j = 0;
    bool inserted = false;
    for(int i =0 ; i < smallstr.length(); ++i){
       if(smallstr[i] == bigstr[j]){
           j++;
           continue;
       } else {
           if(inserted) {
               return false;
           } else {
               inserted = true;
               i--;
           }
       }
       j++;
    }
    return true;
}

bool isOneAway(string str1, string str2){
    if( str1.length() == NULL  && str2.length() == NULL){
        return true;
    }
    if(str1.length() == str2.length()){
       return checkReplace(str1, str2);
    } else if (str1.length() < str2.length()+1){
        return checkInsert(str1, str2);
    } else if (str1.length() > str2.length()){
        return checkInsert(str2, str1);
    }
    return false;
}

int main() {
    string str1 = "blle";
    string str2 = "plale";
    bool result;
    result = isOneAway(str1, str2);
    cout<<result;
    return 0;
}