//
// Created by sajith on 8/20/22.
//
#include "base.h"

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        for (const auto &sh: shifts)
        {
            auto start = sh[0];
            auto end = sh[1];
            auto direction = sh[2];
            if (direction == 0)
            {
                for (int i = start; i <= end; ++i)
                {
                    auto ind = (25 + s[i] - 'a') % 26 + 'a';
                    s[i] = char(ind);
                }
                cout << s << endl;
            }
            else
            {
                for (int i = start; i <= end; ++i)
                {
                    auto ind = (s[i]-'a') % 26+ 'a';
                    s[i] = char(ind);
                }
                cout << s << endl;
            }
        }
        return s;

    }
};

int main()
{
    Solution so;
    string s{"abc"};
    vector<vector<int>> v{{0, 1, 0},
                          {1, 2, 1},
                          {0, 2, 1}};

    cout << so.shiftingLetters(s, v);

//    cout << int('a');
    return 0;
}