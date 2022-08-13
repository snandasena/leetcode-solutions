//
// Created by sajith on 8/13/22.
//

#include "base.h"

class Solution
{

public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> mp;
        for (const auto &str: words)
        {
            ++mp[str];
        }

        auto N = static_cast<int>(s.size());
        auto word_length = static_cast<int>(words.front().size());
        function<bool(int)> func = [&](int indx)
        {
            unordered_map<string, int> m;
            while (indx < N)
            {
                string right = s.substr(indx, word_length);
                if (mp.find(right) == mp.end())
                {
                    return false;
                }
                else
                {
                    ++m[right];
                    if (m[right] > mp[right]) return false;
                    else if (m == mp) return true;
                    indx += word_length;
                }
            }
            return false;
        };
        vector<int> ans;
        auto words_length = static_cast<int> (words.size() * word_length);
        for (int i = 0; i < N - words_length + 1; ++i)
        {
            if (func(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s{"barfoothefoobarman"};
    vector<string> words{"foo", "bar"};

    auto ans = sol.findSubstring(s, words);

    return 0;
}