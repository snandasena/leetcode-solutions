//
// Created by sajit on 09/05/2024.
//


#include "base.h"

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<>());

        long long ans = 0;
        int remove = 0;
        for (int i = 0; i < k; ++i)
        {
            ans += max(happiness[i] - remove, 0);
            ++remove;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v{7, 50, 3};
    cout << sol.maximumHappinessSum(v, 3) << endl;
    return 0;
}