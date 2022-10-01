//
// Created by sajith on 8/21/22.
//
#include "../base.h"


int longestSubarray(vector<int> arr)
{
    int ans = 1;
    for (int i = 0; i < arr.size(); ++i)
    {
        unordered_set<int> st;
        int j = i;
        for (; j < arr.size(); ++j)
        {
            if (st.size() <= 2)
            {
                st.insert(arr[j]);
            }
            else
            {
                break;
            }
        }

        if (i == 0 && j == arr.size())
        {
            return j;
        }

        ans = max(ans, j - i - 1);
    }

    return ans;
}

int main()
{
    vector<int> v{0, 1, 2, 1, 2, 3};
    cout << longestSubarray(v);
    return 0;
}