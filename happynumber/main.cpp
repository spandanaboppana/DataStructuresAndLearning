#include <iostream>
#include <vector>



using namespace std;

int squarenum(int n){
    int sum = 0;
    while(n > 0){
        sum += (n % 10)*(n%10);
        n = n/10;
    }
    return sum;

}

bool isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = squarenum(slow);
        fast = squarenum(squarenum(fast));
    } while (slow != fast);

    cout<<slow;
    return (slow == 1);
}


int main() {
    bool result = isHappy(19);
    cout<<result;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}