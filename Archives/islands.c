#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Assuming a maximum size for the grid

typedef struct {
    int m;
    int n;
    char grid[MAX_SIZE][MAX_SIZE];
    bool seen[MAX_SIZE][MAX_SIZE];
    int directions[4][2];
} Solution;

void initSolution(Solution *sol, char inputGrid[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    sol->m = rows;
    sol->n = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sol->grid[i][j] = inputGrid[i][j];
            sol->seen[i][j] = false;
        }
    }
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    memcpy(sol->directions, dirs, sizeof(dirs));
}

bool valid(Solution *sol, int row, int col) {
    return row >= 0 && row < sol->m && col >= 0 && col < sol->n && sol->grid[row][col] == '1';
}

void dfs(Solution *sol, int row, int col) {
    for (int i = 0; i < 4; i++) {
        int nextRow = row + sol->directions[i][0];
        int nextCol = col + sol->directions[i][1];
        if (valid(sol, nextRow, nextCol) && !sol->seen[nextRow][nextCol]) {
            sol->seen[nextRow][nextCol] = true;
            dfs(sol, nextRow, nextCol);
        }
    }
}

int numIslands(Solution *sol) {
    int ans = 0;
    for (int row = 0; row < sol->m; row++) {
        for (int col = 0; col < sol->n; col++) {
            if (sol->grid[row][col] == '1' && !sol->seen[row][col]) {
                ans++;
                sol->seen[row][col] = true;
                dfs(sol, row, col);
            }
        }
    }
    return ans;
}

int main() {
    Solution sol;
    char grid[MAX_SIZE][MAX_SIZE] = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    initSolution(&sol, grid, 4, 5);
    printf("Number of Islands: %d\n", numIslands(&sol));
    return 0;
}