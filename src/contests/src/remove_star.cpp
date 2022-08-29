//
// Created by sajith on 8/28/22.
//
#include "base.h"

class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> st;
        for (const auto &item: s)
        {
            if (item != '*')
            {
                st.push(item);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
        }

        string ans;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;


    }
};


int main()
{

    Solution solution;
    cout << solution.removeStars("erase*****");
}