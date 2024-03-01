#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        sort(s.begin(), s.end(), greater<>());
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == '0')
            {
                swap(s[i - 1], s[s.size() - 1]);
                break;
            }
        }
        return s;
    }
};

int main()
{
    Solution sol;
    cout << sol.maximumOddBinaryNumber("0110");
    return 0;
}
