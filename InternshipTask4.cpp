#include <iostream>
using namespace std;

// Define the size of the Sudoku grid
#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if the given digit can be placed in the given row and column
bool isSafe(int grid[N][N], int row, int col, int num) {
    
    // Check if the num is not already present in the current row, current column, and current 3x3 grid
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num || grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return false;
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // Find an empty cell
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // If there is no empty cell, puzzle is solved
    if (!isEmpty) {
        return true;
    }

    // Try placing digits from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        // Check if the current digit can be placed in the empty cell
        if (isSafe(grid, row, col, num)) {
            // Place the digit in the empty cell
            grid[row][col] = num;

            // Recursively solve the puzzle
            if (solveSudoku(grid)) {
                return true;
            }
            
            // If placing the current digit leads to contradiction, backtrack
            grid[row][col] = 0;
        }
    }


    // If no digit can be placed, puzzle is unsolvable
    return false;
}

int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) {
        cout << "Sudoku puzzle solved successfully:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }

    return 0;
}
