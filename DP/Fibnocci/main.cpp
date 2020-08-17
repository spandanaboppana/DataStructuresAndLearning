#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return fib(n-2) + fib(n-1);
}

int main() {
    cout<<fib(4);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}