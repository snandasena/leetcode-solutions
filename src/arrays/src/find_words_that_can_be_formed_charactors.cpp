//
// Created by sajit on 02/12/2023.
//

#include "base.h"

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> v(26, 0);
        for (const auto &ch: chars)
        {
            ++v[ch - 'a'];
        }

        int ans = 0;
        for (const auto &word: words)
        {
            vector<int> charCount(26, 0);
            for (const auto &ch: word)
            {
                ++charCount[ch - 'a'];
            }

            bool found = true;
            for (int i = 0; i < 26; ++i)
            {
                if (v[i] < charCount[i])
                {
                    found = false;
                    break;
                }
            }
            if (found)
                ans += word.length();
        }
        return ans;
    }
};