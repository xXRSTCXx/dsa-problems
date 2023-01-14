#include <bits/stdc++.h>

using namespace std;

void markIsland(bool** matrix, int rows, int cols, int r, int c, bool** visited) {
    int curr = matrix[r][c];

    // if the cell has been visited, immediately exit
    if (visited[r][c])
        return;

    // mark cell as visited
    visited[r][c] = true;

    //up
    if (r - 1 >= 0) {
        int cell_up = matrix[r - 1][c];
        if (cell_up == curr) {
            markIsland(matrix, rows, cols, r - 1, c, visited);
        }
    }
    // down
    if (r + 1 < rows) {
        int cell_down = matrix[r + 1][c];
        if (cell_down == curr) {
            markIsland(matrix, rows, cols, r + 1, c, visited);
        }
    }
    //left 
    if (c - 1 >= 0) {
        int cell_left = matrix[r][c - 1];
        if (cell_left == curr) {
            markIsland(matrix, rows, cols, r, c - 1, visited);
        }
    }
    //right
    if (c + 1 < cols) {
        int cell_right = matrix[r][c + 1];
        if (cell_right == curr) {
            markIsland(matrix, rows, cols, r, c + 1, visited);
        }
    }
}

int binaryIslands(bool** matrix, int rows, int cols) {
    bool** visited = new bool*[rows];

    for(int r = 0; r < rows; r++) {
        visited[r] = new bool[cols];
        for(int c = 0; c < cols; c++) {
            visited[r][c] = false;
        }
    }

    int islands = 0;

    // traverse through entire matrix
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            // if this cell was already visited then it must be part of an island
            if (visited[r][c])
                continue;

            // mark all cells in the island as visited
            markIsland(matrix, rows, cols, r, c, visited);

            islands++;
        }
    }

    return islands;
}

int main(int argc, char const* argv[])
{
    int rows, columns;
    cin >> rows >> columns;

    bool* matrix[rows];

    for (int r = 0; r < rows; r++) {
        matrix[r] = (bool*)malloc(sizeof(bool) * columns);
        for (int c = 0; c < columns; c++) {
            cin >> matrix[r][c];
        }
    }

    int islands = binaryIslands(matrix, rows, columns);

    cout << islands;

    return 0;
}
