//
// Created by sajith on 10/14/22.
//

#include "base.h"

struct Trie
{
    bool is_end = false;
    unordered_map<char, Trie *> children;

    bool search(const string &str)
    {
        Trie *curr = this;
        for (const auto &item: str)
        {
            if (curr->children[item] == nullptr)
            {
                return false;
            }
            curr = curr->children[item];
        }

        if (curr->is_end)
        {
            return true;
        }
        return false;
    }

    void insert(const string &str)
    {
        Trie *curr = this;
        for (const auto &item: str)
        {
            if (curr->children[item] == nullptr)
            {
                curr->children[item] = new Trie;
            }
            curr = curr->children[item];
        }
        curr->is_end = true;
    }
};

class Solution
{
    string str;
    unordered_set<string> st;
    vector<int> dp;

    int helper(int indx)
    {
        if (indx == str.size())
        {
            return 1;
        }

        if (dp[indx] != -1)
        {
            return dp[indx];
        }

        string temp;
        int ans = 0;
        for (int i = indx; i < str.size(); ++i)
        {
            temp += str[i];
            if (st.find(temp) != st.end())
            {
                if (helper(i + 1) == 1)
                {
                    ans = 1;
                    break;
                }
            }
        }
        return dp[indx] = ans;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        str = s;
        for (const auto &ele: wordDict)
        {
            st.insert(ele);
        }
        dp.resize(s.size() + 1, -1);
        return helper(0);
    }
};

int main()
{
    Solution sol;
    vector<string> v{"cats", "dog", "sand", "and", "cat"};
    string s{"catsandog"};

    cout << boolalpha << sol.wordBreak(s, v);
    return 0;
}