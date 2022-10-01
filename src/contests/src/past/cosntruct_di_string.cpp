//
// Created by sajith on 8/14/22.
//

#include "../base.h"

class Solution
{
public:
    string smallestNumber(string p)
    {
        string ans;
        stack<int> st;
        int num = 1;
        for (auto itr = p.begin(); itr != p.end(); ++itr)
        {
            if (*itr == 'D')
            {
                st.push(num);
                ++num;
            }
            else
            {
                st.push(num);
                ++num;
                while (!st.empty())
                {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(num);
        while (!st.empty())
        {
            ans += to_string(st.top());
            st.pop();
        }
        return ans;
    }
};


int main()
{

    Solution solution;
    string S{"DDD"};

    cout << solution.smallestNumber(S);
    return 0;
}