//
// Created by sajith on 11/19/22.
//


#include "base.h"

class Solution
{

    vector<int> bottomLeft(vector<vector<int>> &points)
    {
        vector<int> bm(points[0]);

        for(const auto &p: points)
        {
            if(p[1] < bm[1])
            {

            }
        }

    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &points)
    {
        if (points.size() <= 1)
        {
            return points;
        }


    }
};