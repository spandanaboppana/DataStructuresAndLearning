#include <iostream>

/**
 *
 * @param matrix1 input matrix 1
 * @param m1 number of rows in m1
 * @param n1 number of cols in m1
 * @param matrix2 input matrix 2
 * @param m2 number of rows in m2
 * @param n2 number of cols in m2
 */
void printMatrix(int **matrix1, const size_t m1, const size_t n1, int **matrix2, const size_t m2, const size_t n2)
{

}

int main()
{
    const size_t M1 = 5;
    const size_t N1 = 3;

    // empty initializer list
    int **matrix1;
    matrix1 = new int *[M1];
    for(int i = 0; i <M1; i++)
        matrix1[i] = new int[N1];

    for (int i = 0; i < M1; ++i) {
        for (int j = 0; j < N1; ++j) {
            matrix1[i][j] = i * j;
        }
    }

    const size_t M2 = 3;
    const size_t N2 = 4;

    // empty initializer list
    int **matrix2;
    matrix2 = new int *[M2];
    for(int i = 0; i <M2; i++)
        matrix2[i] = new int[N2];

    for (int i = 0; i < M2; ++i) {
        for (int j = 0; j < N2; ++j) {
            matrix2[i][j] = i * j;
        }
    }

    printMatrix(matrix1, M1, N1, matrix2, M2, N2);
    return 0;
}
