#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string>  printInterleaved(string string1, string string2);
void printStr(string s) { cout << s << " "; }
int main()
{
    vector<string> output = printInterleaved("ab","cd");
    vector<string> outputRequired = {"abcd", "acbd", "acdb", "cdab", "cadb", "cabd"};
    cout << "required output= ";
    for_each (outputRequired.begin(), outputRequired.end(), printStr);
    cout << endl;
    cout << "Obtained output= ";
    for_each (output.begin(), output.end(), printStr);
    cout << endl;
    return 0;
}

void util(string current, string string1, string string2, vector<string> &result){

    if(!string1.length() && !string2.length()){
        result.push_back(current);
        return;
    }

    if(string1.length() == 0){
        result.push_back(current + string2.substr(0));
        return;
    }

    if(string2.length() == 0){
        result.push_back(current + string1.substr(0));
        return;
    }


    util(current + string1[0], string1.substr(1), string2, result);
    util(current + string2[0], string1, string2.substr(1), result);
}

vector<string> printInterleaved(string string1, string string2) {
    vector<string>result;
    util("", string1, string2, result);
    return result;
}