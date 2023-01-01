//
// Created by sajith on 1/1/23.
//

#include "base.h"

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp;
        unordered_set<string> st;
        string temp;
        int i = 0;
        for (const auto &ch: pattern)
        {
            temp = "";
            while (i < s.length() && s[i] != ' ')
            {
                temp += s[i];
                ++i;
            }
            ++i;

            if (mp.find(ch) == mp.end() )
            {
                if(st.find(temp) == st.end())
                {
                    mp[ch] = temp;
                    st.insert(temp);
                }else
                {
                    return false;
                }
            }
            else if (mp[ch] != temp)
            {
                return false;
            }
        }

        if(--i !=s.length())
        {
            return false;
        }

        return true;
    }
};

int main()
{

    Solution sol;
    cout << boolalpha << sol.wordPattern("abba", "dog cat cat dog");
}