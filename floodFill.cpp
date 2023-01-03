#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color, int startColor = -1) {
    if (startColor == -1)
        startColor = image[sr][sc];

    if (startColor == color || sr < 0 || sr > image.size() - 1 || sc < 0 || sc > image[0].size() - 1 || image[sr][sc] != startColor) {
        return image;
    }

    // if nothing is out of bounds
    image[sr][sc] = color;
    floodFill(image, sr - 1, sc, color, startColor);
    floodFill(image, sr + 1, sc, color, startColor);
    floodFill(image, sr, sc - 1, color, startColor);
    floodFill(image, sr, sc + 1, color, startColor);

    return image;
}

int main(int argc, char const* argv[])
{
    vector<vector<int>> image = {
        // {1, 1, 1},
        // {1, 1, 0},
        // {1, 0, 1},
        {0, 0, 0},
        {0, 0, 0},
    };
    vector<vector<int>> matrix = {
        {1, 1, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 1},
        {1, 0, 1, 1},
    };

    floodFill(image, 1, 0, 2);

    for (auto row : image) {
        for (auto column : row) {
            cout << column << "\t";
        }
        cout << "\n";
    }
    return 0;
}
