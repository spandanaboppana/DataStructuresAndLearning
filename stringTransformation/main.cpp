#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/*
 * Complete the function below.
 */

bool is_diff_one_char(string str1, string str2){
    int diff = 0;
    for(int i = 0; i<str1.size(); i++){
            if(str1[i] != str2[i]) {
                if(diff == 1)
                    return false;
                diff++;
            }
        }

    return diff == 1;
}
void build_graph(vector<string> &words, unordered_map<string, vector<string>> &adj_list){


    for(int i=0; i<words.size()-1;i++){

        for(int j=0; j<words.size();j++){
            if(is_diff_one_char(words[i], words[j])){
                adj_list[words[i]].push_back(words[j]);
            }
        }
    }

}


vector<string> string_transformation(vector<string> words, string start, string stop) {
    unordered_map<string, vector<string>> adj_list;
    unordered_map<string, string> back_ref;
    build_graph(words, adj_list);


    vector<string> path;
     bool found = false;

    queue<string> my_queue;

    my_queue.push(start);
    back_ref[start] = " ";
    while(!my_queue.empty()){
        string vertex = my_queue.front();
        my_queue.pop();
        found = false;

        for(auto neighbour : adj_list[vertex]){
            if(back_ref.find(neighbour) != back_ref.end()){
                continue;
            } else {
                back_ref[neighbour] = vertex;
                if (neighbour == stop){
                    found = true;
                    break;
                } else {
                    my_queue.push(neighbour);
                }
            }
        }
        if (found == true){
            break;
        }
    }
    if (back_ref.find(stop) == back_ref.end()){
        path.push_back(" ");
        return path;
    } else {
        string curr = stop;
        while (curr != " ") {
            path.push_back(curr);
            curr = back_ref[curr];
        }
        reverse(path.begin(), path.end());
    }
    return path;

}


int main() {
    vector<string> words{"cat","bar", "car", "bat", "bit", "but"};
    vector<string> result;
    result = string_transformation(words, "cat", "but");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}