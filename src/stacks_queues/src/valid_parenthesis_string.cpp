//
// Created by sajit on 07/04/2024.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int h = 0;
        int l = 0;

        for (auto c: s)
        {
            l += c == '(' ? 1 : -1;
            h += c != ')' ? 1 : -1;

            if (h < 0) break;

            l = max(l, 0);
        }

        return l == 0;
    }
};


int main()
{
    Solution sol;
    string sv{"((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()"};
    cout << boolalpha << sol.checkValidString(sv);
}