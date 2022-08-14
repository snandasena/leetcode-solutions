//
// Created by sajith on 8/14/22.
//


#include "base.h"

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end())
        {
            return 0;
        }

        queue<string> que;
        que.push(beginWord);
        int depth = 0;
        while (!que.empty())
        {
            ++depth;

            auto qsize = que.size();
            while (qsize-- > 0)
            {
                auto curr = que.front();
                que.pop();

                for (auto i = 0; i < curr.size(); ++i)
                {
                    auto temp = curr;
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        temp[i] = c;

                        if (curr == temp) continue;
                        if (temp == endWord) return depth + 1;

                        if (st.find(temp) != st.end())
                        {
                            que.push(temp);
                            st.erase(temp);
                        }
                    }
                }

            }
        }
        return 0;
    }
};