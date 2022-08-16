//
// Created by sajith on 8/16/22.
//


// CPP program for the above approach

#include <bits/stdc++.h>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &A)
{

    int r = A.size();
    int c = A[0].size();

    // If obstacle is at starting position
    if (A[0][0])
        return 0;

    // Initializing starting position
    A[0][0] = 1;

    // first row all are '1' until obstacle
    for (int j = 1; j < c; j++)
    {

        if (A[0][j] == 0)
        {
            A[0][j] = A[0][j - 1];
        }
        else
        {
            // No ways to reach at this index
            A[0][j] = 0;
        }
    }

    // first column all are '1' until obstacle
    for (int i = 1; i < r; i++)
    {

        if (A[i][0] == 0)
        {
            A[i][0] = A[i - 1][0];
        }
        else
        {
            // No ways to reach at this index
            A[i][0] = 0;
        }
    }

    for (int i = 1; i < r; i++)
    {

        for (int j = 1; j < c; j++)
        {
            // If current cell has no obstacle
            if (A[i][j] == 0)
            {

                A[i][j] = A[i - 1][j] + A[i][j - 1];
            }
            else
            {
                // No ways to reach at this index
                A[i][j] = 0;
            }
        }
    }

    // returning the bottom right
    // corner of Grid
    return A[r - 1][c - 1];
}

// Driver Code

int main()
{

    vector<vector<int> > A
            = {{0, 0, 0},
               {0, 1, 0},
               {0, 0, 0}};

    cout << uniquePathsWithObstacles(A) << "\n";

    return 0;
}
// This code is contributed by hemantraj712
