//
// Created by sajit on 02/09/2023.
//
#include <bits/stdc++.h>

using namespace std;


struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool is_word;
};


class Solution
{
private:

    TrieNode *build_trie(const vector<string> &dict)
    {
        auto root = new TrieNode();
        for (const auto &word: dict)
        {
            auto node = root;
            for (const auto &ch: word)
            {
                if (node->children.find(ch) == node->children.end())
                    node->children[ch] = new TrieNode();

                node = node->children[ch];
            }
            node->is_word = true;
        }

        return root;
    }

public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        int n = s.length();
        auto root = build_trie(dictionary);
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int start)
        {
            if (start == n)
                return 0;

            if (memo.count(start))
                return memo[start];

            int ans = dp(start + 1) + 1;
            TrieNode *node = root;

            for (int end = start; end < n; ++end)
            {
                char c = s[end];
                if (node->children.find(c) == node->children.end())
                    break;

                node = node->children[c];
                if (node->is_word)
                    ans = min(ans, dp(end + 1));
            }
            return memo[start] = ans;
        };

        return dp(0);
    }
};


int main()
{

    auto n1 = new TrieNode;
    auto n2 = new TrieNode();

    return 0;
}

