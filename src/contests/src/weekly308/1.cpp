//
// Created by sajith on 9/4/22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkDistances(string s, vector<int> &distance)
    {

        vector<vector<int>> v(26);
        for (int i = 0; i < s.size(); ++i)
        {
            auto idx = s[i] - 'a';
            v[idx].push_back(i);
        }

        for (int i = 0; i < 26; ++i)
        {
            if (!v[i].empty())
            {
                auto l = v[i][0];
                auto m = v[i][1];

                if (distance[i] != m - l - 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string s{"aa"};
    vector<int> d{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout << boolalpha << solution.checkDistances(s, d);
    return 0;
}