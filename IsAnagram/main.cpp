#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s1, string s2);
int main()
{
   bool result =  isAnagram("a","ab");
   cout<<result;
   /* assert(isAnagram("a","ab"));
    assert(isAnagram("abc","cab"));
    assert(isAnagram("aabc","abac"));
    assert(!isAnagram("abc","bad"));
    assert(!isAnagram("abc","ba"));*/
    return 0;
}


/*
 * Returns
 * True if s1 is an anagram of s2
 * false  otherwise.
 * Anagram:
 *
 *  abc bac cba cab are all anagrams of each other
 *  abc and cca are not anagrams of each other
 *  abc and ac are not anagrams either
 */
bool isAnagram(string s, string t) {
    unordered_map<char,int> char_map;

    for(int i=0;i<s.size();i++){
        if(char_map.find(s[i]) == char_map.end()){
            char_map[s[i]] = 1;
        }
        else {
            char_map[s[i]]++;
        }
    }

    for(int i=0;i<t.size();i++){

        if(char_map.find(t[i]) == char_map.end()){
            char_map[t[i]] = 1;
        }

        else {
            char_map[t[i]]--;
            if(char_map[t[i]] == 0){
                char_map.erase(t[i]);
            }
        }
    }

    if(char_map.empty())
        return true;

    else
        return false;


}
