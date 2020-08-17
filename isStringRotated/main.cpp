#include <iostream>
#include <string>
using namespace std;

bool isRotated(string s1, string s2);
int main()
{
   // isRotated("abcde","deabc");
    assert(isRotated("abcde","deabc"));
    assert(isRotated("abcde","cdeab"));
    assert(isRotated("xyz","yzx"));
    assert(!isRotated("xyz","xzy"));
    assert(!isRotated("abcde","edabc"));

    return 0;
}


/*
 * Returns
 * True if s1 is a rotated version of s2
 * false  otherwise.
 * Rotation:
 * abcde  deabc   returns true
 * abcde  cdeab   returns true
 * abcde  edabc   returns false
 * xyz yzx        returns true
 * xyz xzy        returns false
 *
 * abcdeabcde
 */

bool checkifs2issubstringofnewstring(string s1, string s2){
    int n = s2.size();
    for(int i=0;i<s1.size()-n;i++){
       string str =  s1.substr(i,n);
       if(str == s2)
           return true;
    }
    return false;
}
bool isRotated(string s1, string s2) {

    string newstring = s1.append(s1);
    return checkifs2issubstringofnewstring(newstring,s2);
}