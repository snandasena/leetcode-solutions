//
// Created by sajith on 9/19/22.
//
#include "base.h"

class Solution
{
    unordered_map<string, vector<string>> mp;
    pair<string, string> get_content(string &str)
    {
        str.pop_back();
        auto itr = str.find('(');
        return {str.substr(0, itr), str.substr(++itr)};
    }
public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        string token;
        string dir;
        bool flag;
        for (const auto &str: paths)
        {
            stringstream ss{str};
            token.clear();
            flag = false;
            dir.clear();
            while (ss >> token)
            {
                if (!flag)
                {
                    dir = token;
                    flag = true;
                }
                else
                {
                    auto [file_name, content] = get_content(token);
                    file_name = dir + '/' + file_name;
                    mp[content].push_back(file_name);
                }
            }
        }

        vector<vector<string>> ans;
        for (const auto &[k, v]: mp)
        {
            if (v.size() > 1)
            {
                ans.push_back(v);
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> v{"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)",
                     "root 4.txt(efgh)"};

    Solution sol;
//    sol.findDuplicate(v);

    string str{"root/a 1.txt(abcd) 2.txt(efgh)"};

    string token;
    stringstream ss{str};
    ss << token;

    cout << token;

    return 0;
}