//
// Created by sajith on 8/1/22.
//


#include "base.h"

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_set<char> st;
        for (const auto &item: p)
        {
            st.insert(item);
        }

        vector<int> ans;
        for (int i = 0; i < s.size(); ++i)
        {
            if (st.find(s[i]) != st.end())
            {
                int k = 1;
                for (int j = i + 1; j < s.size(); ++j)
                {
                    if (st.find(s[j]) == st.end())
                    {
                        break;
                    }
                    else
                    {
                        ++k;
                    }

                    if (k == st.size())
                    {
                        ans.push_back(i);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s{"cbaebabacd"};
    string p{"abc"};
    sol.findAnagrams(s, p);
    return 0;
}