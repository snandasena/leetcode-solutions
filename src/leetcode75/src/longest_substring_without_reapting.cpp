
//
// Created by sajith on 8/18/22.
//

#include "base.h"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        vector<int> v(256, 0);
        int j;
        unordered_set<char> st;
        for (auto i = 0; i < s.size(); ++i)
        {
            j = i;

            while (j < s.size() && st.find(s[j]) == st.end())
            {
                st.insert(s[j]);
                ++j;
            }
            ans = max(static_cast<int>(st.size()), ans);
            st.clear();
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s{"a"};

    cout << sol.lengthOfLongestSubstring(s);

    return 0;
}