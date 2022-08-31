//
// Created by sajith on 8/30/22.
//


#include "base.h"

class Solution
{
    void dfs(vector<vector<int>> &image, int i, int j, int color, int start_color)
    {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != start_color)
        {
            return;
        }

        image[i][j] = color;
        dfs(image, i, j + 1, color, start_color);
        dfs(image, i + 1, j, color, start_color);
        dfs(image, i - 1, j, color, start_color);
        dfs(image, i, j - 1, color, start_color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
        {
            return image;
        }
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};