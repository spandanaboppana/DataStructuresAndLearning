#include <iostream>
#include <string>
using namespace std;

void reverseSentence(string& input);

int main()
{
    string input = "A white cat leaped over a brown dog";

    string output = "dog brown a over leaped cat white A";
    reverseSentence(input);

    assert(input == output);
    return 0;
}


/*
 * Problem 1;
 * Input: A white cat leaped over a brown dog
 * output: dog brown a over leaped cat white A
 */
void reverse(string &input,int i, int j){
    char temp;
    while(i<j){
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }
}
void reverseSentence(string& input) {
   int i=0, j=input.size()-1;
   reverse(input,i,j);
    //cout << input;
   i=0;j=i+1;

   while(j<input.size()){
       if(input[j] == ' '){
           reverse(input,i,j-1);
           j++;
           i = j;
       }
       else {
           j++;
       }
   }
}
