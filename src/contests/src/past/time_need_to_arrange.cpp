//
// Created by sajith on 8/20/22.
//

#include "../base.h"


class Solution
{
public:
    int secondsToRemoveOccurrences(string s)
    {
        if (s.size() == 1)
        {
            return 0;
        }
        int ans = 0;
        while (true)
        {
            int curr = 0;
            for (int j = 0; j < s.size() - 1; ++j)
            {
                if (s[j] == '0' && s[j + 1] == '1')
                {
                    s[j] = '1';
                    s[j + 1] = '0';
                    ++curr;
                    ++j;
                }
            }
            if (curr == 0)
            {
                break;
            }
            else
            {
                ++ans;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s{"11100"};
    cout << solution.secondsToRemoveOccurrences(s);
}