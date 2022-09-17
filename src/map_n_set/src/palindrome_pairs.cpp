//
// Created by sajith on 9/17/22.
//

#include "base.h"

class Solution
{

    struct Trie
    {
        vector<Trie *> child;

        Trie()
        {
            child.resize(26, nullptr);
        };

        int indx = -1;
        vector<int> word_indexes;
    };

    bool IsPalindrome(const string &str, int j, int i = 0)
    {
        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }

    void insert(Trie *root, const string &str, int index)
    {
        Trie *curr = root;
        for (auto itr = str.rbegin(); itr != str.rend(); ++itr)
        {
            auto c = *itr - 'a';
            if (curr->child[c] == nullptr)
            {
                curr->child[c] = new Trie;
            }

            if (IsPalindrome(str, itr - str.rbegin()))
            {
                curr->word_indexes.push_back(index);
            }
            curr = curr->child[c];
        }
    }
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        Trie *root = new Trie;

    }
};