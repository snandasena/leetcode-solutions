//
// Created by sajith on 8/14/22.
//

#include "base.h"

class Solution
{
    vector<vector<string>> ans;

    void dfs(const string &beginWord, const string &endWord, unordered_map<string, unordered_set<string>> &adj,
             vector<string> &path)
    {
        path.push_back(beginWord);

        if (beginWord == endWord)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for (const auto &word: adj[beginWord])
        {
            dfs(word, endWord, adj, path);
        }
        path.pop_back();
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, unordered_set<string>> adj;
        unordered_set<string> dict(wordList.begin(), wordList.end());

        queue<string> que;
        que.push(beginWord);

        unordered_map<string, int> visited;
        visited[beginWord] = 0;

        while (!que.empty())
        {
            auto curr = que.front();
            que.pop();
            auto temp = curr;

            for (auto i = 0; i < curr.size(); ++i)
            {
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    if (temp[i] == c) continue;

                    temp[i] = c;

                    if (dict.count(temp) > 0)
                    {
                        if (visited.count(temp) == 0)
                        {
                            visited[temp] = visited[curr] + 1;
                            que.push(temp);
                            adj[curr].insert(temp);
                        }
                        else if (visited[temp] == visited[curr] + 1)
                        {
                            adj[curr].insert(temp);
                        }
                    }
                }
                temp[i] = curr[i];
            }
        }

        vector<string> path;
        dfs(beginWord, endWord, adj, path);
        return ans;
    }
};