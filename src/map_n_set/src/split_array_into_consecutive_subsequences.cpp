//
// Created by sajith on 8/19/22.
//

#include "base.h"

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_set<int> st;
        int i = 0;
        for (; i < nums.size(); ++i)
        {
            st.insert(nums[i]);
            if (st.size() == 3)
            {
                break;
            }
        }
        ++i;
        unordered_set<int> st2;
        for (; i < nums.size(); ++i)
        {
            st2.insert(nums[i]);
            if (st2.size() == 3)
            {
                break;
            }
        }
        return st.size() >= 3 && st.size() == st2.size();
    }
};


int main()
{
    Solution sol;
    vector<int> v{1, 2, 3, 3, 4, 5};
    cout << boolalpha << sol.isPossible(v) << endl;
    return 0;
}