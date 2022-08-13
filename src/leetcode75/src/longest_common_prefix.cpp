//
// Created by sajith on 8/13/22.
//


#include "base.h"

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans;
        char curr;
        for (int i = 0; i < strs.front().size(); ++i)
        {
            curr = strs.front()[i];
            auto itr = strs.begin();
            ++itr;
            bool flag = false;
            while (itr != strs.end())
            {
                if (itr->size() <=i || itr->at(i) != curr)
                {
                    flag = true;
                    break;
                }
                ++itr;
            }
            if (flag) break;
            ans += curr;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> strs{"al","a"};
    cout << sol.longestCommonPrefix(strs);
    return 0;
}