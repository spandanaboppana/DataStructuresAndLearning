#include <iostream>
#include <vector>

using namespace std;

void clearZeroes( int (&input)[4][5], int row = 4, int cols = 5);
bool checkValues(int (&a)[4][5], int (&b)[4][5], int rows = 4, int cols = 5) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (a[i][j] != b[i][j]) return false;
    return true;
}

void printMatrix( int (&input)[4][5], int rows = 4, int cols = 5){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << (input[i][j]) << " ";
        }
        cout << endl;
    }
}
int main(){
    int matrix[4][5] = {
            1,2,8,7,4,
            8,0,3,9,5,
            7,5,3,2,9,
            0,9,0,1,7
    };
    int resultMatrix[4][5] = {
            0,0,0,7,4,
            0,0,0,0,0,
            0,0,0,2,9,
            0,0,0,0,0
    };

    clearZeroes(matrix);
    cout << "printing output matrix" << endl;
    printMatrix(matrix);
    assert(checkValues(matrix, resultMatrix));
    return 0;
}




/*
 * In this matrix, if a cell x,y is zero, the entire row x and col y must be set to 0
 *
            1,2,8,7,4,
            8,0,3,9,5,
            7,5,3,2,9,
            0,9,0,1,7

            Output
            0,0,0,7,4,
            0,0,0,0,0,
            0,0,0,2,9,
            0,0,0,0,0
 */


void clearZeroes( int (&input)[4][5], int row, int col) {
    vector<int> rows(row,1);
    vector<int> cols(col,1);
    for(int i = 0; i<row;i++){
        for(int j = 0; j<col;j++){
            if(input[i][j] == 0){
                rows[i] = 0;
                cols[j] = 0;
            }
        }
    }

    for(int i = 0; i<row;i++){
        for(int j = 0; j<col;j++){
            if(rows[i] == 0 || cols[j] == 0){
                input[i][j] = 0;
            }
        }
    }

}