
//
// Created by sajith on 8/20/22.
//


#include "../base.h"

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int N = blocks.size();
        int mx = 0;
        for (int i = 0; i < N; ++i)
        {
            int curr = 0;
            for (int j = i; j < i + k && j < N; ++j)
            {
                if (blocks[j] == 'B')
                {
                    ++curr;
                }
            }
            mx = max(curr, mx);
        }
        return mx >= k ? 0 : k - mx;
    }
};


int main()
{

    Solution solution;
    string s{"WWWBBBBW"};
    int k = 0;
    cout << solution.minimumRecolors(s, k);
}