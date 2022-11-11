//
// Created by sajith on 11/8/22.
//

#include "base.h"

bool islower(char ch)
{
    return (ch >= 97 && ch <= 122);
}
bool isupper(char ch)
{
    return (ch >= 65 && ch <= 90);
}

bool check(const char a, const char b)
{

    return ((islower(a) && isupper(b)) || (islower(b) && isupper(a))) && (tolower(a) == tolower(b));
}

class Solution
{

public:
    string makeGood(string s)
    {
        stack<char> st;
        for (const auto &ch: s)
        {
            if (st.empty())
            {
                st.push(ch);
            }
            else
            {
                if (check(ch, st.top()))
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
        }

        string ans;
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main()
{
    Solution sol;
    cout << sol.makeGood("kkdsFuqUfSDKK");

}