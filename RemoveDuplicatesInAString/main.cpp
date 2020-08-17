#include <iostream>
#include <string>
using namespace std;

char* returnDuplicateRemovedString(char *input) {
    int copyto;
    int copyfrom;
    int current;
    int len = strlen(input);

    for(int i=0;i<strlen(input);i++) {
        current = i;
        copyfrom = i+1;
        copyto = i+1;
        while(copyfrom < strlen(input)) {
            if(input[copyfrom] == input[current]) {
                copyfrom++;
            } else {
                cout << "copyto" << input[copyto];
                cout << "copyfrom" << input[copyfrom];
                input[copyto] = input[copyfrom];
                copyfrom++;
                copyto++;
            }

        }
        input[copyto] = '\0';
    }
    return input;
}
int main() {
    char* result = returnDuplicateRemovedString("aabb");
    cout << result;
    //assert(returnDuplicateRemovedString("aabbaabab") == "ab");
    assert(returnDuplicateRemovedString("abcdabtrti") == "abcdtri");
    return 0;
}

