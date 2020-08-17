#include <iostream>
using namespace std;

bool PalindromePermutation(string input){
    int checker = 0;
    int temp = checker;

    for(int i =0; i<input.length(); i++){
        int k = input[i] - 'a';
        int mask = 1 << k;
        if(checker & mask == 0) {
            checker |= mask;
        } else {
            checker = (checker & ~(mask));
        }

    }
    return (checker & (checker-1)) == 0;

}

int main() {

    bool result = PalindromePermutation("Tact Coa");
    cout << result;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}