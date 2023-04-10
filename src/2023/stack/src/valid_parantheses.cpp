//
// Created by sajit on 10/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    unordered_map<char, char> parentheses{{']', '['},
                                          {'}', '{'},
                                          {')', '('}};
public:
    bool isValid(string s)
    {
        if (s.empty())
            return true;

        stack<char> stk;
        auto i = 0u;
        while (i < s.size())
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else if (!stk.empty() && stk.top() == parentheses[s[i]])
                stk.pop();
            else
                return false;

            ++i;
        }
        return stk.empty();
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    cout << sol.isValid("()") << endl;
    cout << sol.isValid("()[]") << endl;
    cout << sol.isValid("(){}[]") << endl;
    cout << sol.isValid("())") << endl;
    cout << sol.isValid("({)}") << endl;

}