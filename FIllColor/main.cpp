#include <iostream>

bool compareMatrices(int matrix1[][10], int matrix2[][10], int rows, int cols)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if  (matrix1[i][j] != matrix2[i][j]) return false;
        }
    }
    return true;
}

/*
 * In this problem a screen is represented as a 2d matrix and it initially contains the following values
 *  0 - indicates that the cell is vacant
 *  1 - indicates a wall or a line drawn
 *
 * In this problem you are given a screen and a position x, y. Imagine you are pouring color at x,y
 * similar to a fill button in MSPaint. The Fill button fills all the screen with paint if the position x,y is not bounded by a wall
 * Otherwise if x,y is bounded by a wall, it fills the inside of the wall with paint.
 *
 * paint the given screen with given color 'color'
 * WRITE CODE BELOW
 */
bool isSafe(int rows, int cols, int x , int y){
    if(x < 0 || x >= rows || y<0 || y>= cols) {
        return false;
    }
    else {
        return true;
    }
}

void fillColor(int (&screen)[][10], int rows, int cols, int x, int y, int color) {

    if(screen[x][y] == 1 || screen[x][y] == color){
        return;
    }
    if (!isSafe(rows,cols,x,y)) return;

    if(screen[x][y] == 0) {
        screen[x][y] = color;
        fillColor(screen, rows, cols, x-1, y, color);
        fillColor(screen, rows, cols, x, y+1, color);
        fillColor(screen, rows, cols, x+1, y, color);
        fillColor(screen, rows, cols, x, y-1, color);
        fillColor(screen, rows, cols, x-1, y-1, color);
        fillColor(screen, rows, cols, x-1, y+1, color);
        fillColor(screen, rows, cols, x+1, y+1, color);
        fillColor(screen, rows, cols, x+1, y-1, color);
    }
    return;
}

int main()
{
    int screen1[10][10] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int outputNeededForScreen1[10][10] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 9, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 9, 1, 1, 1, 0, 0, 0},
            {0, 0, 1, 9, 9, 9, 1, 1, 0, 0},
            {0, 0, 1, 9, 9, 9, 9, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    fillColor(reinterpret_cast<int (&)[][10]>(screen1), 10, 10, 3, 3, 9);
    assert(compareMatrices(screen1, outputNeededForScreen1, 10, 10));
    int screen2[7][10] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}
    };
    int outputNeededForScreen2[7][10] = {
            {9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
            {9, 9, 1, 9, 1, 9, 9, 9, 9, 9},
            {9, 9, 1, 9, 1, 9, 9, 9, 9, 9},
            {9, 9, 1, 9, 1, 1, 1, 9, 9, 9},
            {9, 9, 1, 9, 9, 9, 1, 1, 9, 9},
            {9, 9, 1, 9, 9, 9, 9, 1, 9, 9},
            {9, 9, 1, 1, 1, 1, 1, 1, 9, 9}
    };
    fillColor(reinterpret_cast<int (&)[][10]>(screen2), 7, 10, 3, 3, 9);

    assert(compareMatrices(screen2, outputNeededForScreen2, 7, 10));
    return 0;
}

