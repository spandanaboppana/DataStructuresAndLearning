#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include<algorithm>
#include <unordered_map>


using namespace std;

struct entry {
    int cnt;
    string val;
};

vector<string> solve(vector<string> arr) {
    unordered_map<string, entry> my_map;
    vector<string> result;

        for(auto it = arr.rbegin(); it != arr.rend(); it++) {
            string s = *it;
            int pos = s.find(" ");

            string temp_key = s.substr(0, pos);
            string temp_val = s.substr(pos+1);

            if(my_map.find(temp_key) != my_map.end()){
                if(lexicographical_compare(my_map[temp_key].val.begin(), my_map[temp_key].val.begin()+ my_map[temp_key].val.length(), temp_val.begin(), temp_val.begin()+temp_val.length())){
                    my_map[temp_key].val = temp_val;
                }
            } else {
                my_map[temp_key].val = temp_val;

            }
            my_map[temp_key].cnt++;
        }

        for(auto it: my_map){
            string str;
            str.append(it.first);
            str.append(":");
            str.append(to_string(it.second.cnt));
            str.append(",");
            str.append(it.second.val);
            result.push_back(str);
        }
        return result;

}

int main() {
    vector<string> arr{"key1 abcd", "key2 zzz", "key1 hello", "key3 world", "key1 hello"};
    vector<string> result;
    result = solve(arr);
    for(int i =0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}