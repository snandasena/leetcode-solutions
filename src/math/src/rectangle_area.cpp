//
// Created by sajith on 11/17/22.
//

#include "base.h"

class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int left = abs((ax2 - ax1) * (ay2 - ay1));
        int right = abs((by2 - by1) * (bx2 - bx1));
        int xinterection = min(ax2, bx2) - max(ax1, bx1);
        int yintersection = min(ay2, by2) - max(ay1, by1);
        int intersection = 0;
        if (xinterection > 0 && yintersection > 0)
        {
            intersection = xinterection * yintersection;
        }
        return (left + right - intersection);
    }
};