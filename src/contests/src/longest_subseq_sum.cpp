//
// Created by sajith on 8/28/22.
//

#include "base.h"

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int curr;
        int mx;
        int curr_mx;
        for (int i = 0; i < queries.size(); ++i)
        {
            mx = 0;
            curr_mx = 0;
            curr = 0;
            for (int j = 0; j < nums.size(); ++j)
            {
                curr += nums[j];
                if (curr > queries[i])
                {
                    break;
                }
                else
                {
                    ++curr_mx;
                }
            }

            mx = max(curr_mx, mx);
            ans.push_back(mx);
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    /**
     * [736411,184882,914641,37925,214915]
[331244,273144,118983,118252,305688,718089,665450]
     */

    vector<int> v{736411, 184882, 914641, 37925, 214915};
    vector<int> q{331244,273144,118983,118252,305688,718089,665450};

    auto ans = sol.answerQueries(v, q);
    for (const auto &item: ans)
    {
        cout << item << '\t';
    }
    return 0;
}