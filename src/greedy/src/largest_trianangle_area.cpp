//
// Created by sajith on 10/12/22.
//

#include "base.h"


class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        int minx = INT_MAX;
        int maxx = INT_MIN;
        int miny = INT_MAX;
        int maxy = INT_MIN;

        for (int i = 0; i < points.size(); ++i)
        {
            int x = points[i][0];
            int y = points[i][1];

            minx = min(x, minx);
            maxx = max(x, maxx);

            miny = min(y, miny);
            maxy = max(y, maxy);
        }

        double X = maxx - minx;
        double Y = maxy - miny;

        return abs((Y * Y) / 2);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v{{4, 6},
                          {6, 5},
                          {3, 1}};

    cout<< sol.largestTriangleArea(v);
}