#include <iostream>
#include <string>

using namespace std;

void printMatrix( int (&input)[4][4]){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << (input[i][j]) << " ";
        }
        cout << endl;
    }
}

void reverse(int (&arr)[], int cols) {
    int i=0;

    int j=cols-1;

    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    return;
}

void rotateMatrix(int (&input)[4][4], int rows, int cols){
    //Transpose of a matrix
    for(int i =0; i<rows; i++){
        for(int j =0; j<cols; j++){
            swap(input[i][j], input[j][i]);
        }
    }
    // Reverse the whole array for every row.
    for(int i=0; i<rows; i++){
        reverse(*input[i], cols);
    }
    return;
}

int main() {
    int matrix[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

    rotateMatrix(matrix, 4, 4);
    printMatrix(matrix);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}