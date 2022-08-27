//
// Created by sajith on 8/27/22.
//


#include "base.h"

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        auto n = matrix.size();
        auto m = matrix[0].size();
        int ans = INT_MIN;
        for (int l = 0; l < m; ++l)
        {
            vector<int> sum(n, 0);

            for (int r = l; r < m; ++r)
            {
                for (int i = 0; i < n; ++i)
                {
                    sum[i] += matrix[i][r];
                }

                set<int> st{0};
                int curr_sum = 0;

                for (const auto ele: sum)
                {
                    curr_sum += ele;
                    auto itr = st.lower_bound(curr_sum - k);
                    if (itr != st.end())
                    {
                        ans = max(ans, curr_sum - *itr);
                    }
                    st.insert(curr_sum);
                }
            }
        }
        return ans;
    }
};