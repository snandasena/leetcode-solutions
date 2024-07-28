//
// Created by sajit on 05/06/2024.
//

#include "base.h"

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> ans;
        
        for ( auto &ch: words[0])
        {
            bool flag = true;
            for (unsigned i = 1; i < words.size(); ++i)
            {
                if (words[i].find(ch) == string::npos)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                ans.emplace_back(string{char(ch)});
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> v{"bella", "label", "roller"};
    sol.commonChars(v);

}