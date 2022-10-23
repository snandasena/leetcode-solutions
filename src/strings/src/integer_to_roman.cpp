//
// Created by sajith on 10/20/22.
//

#include "base.h"

const vector<pair<int, string>> mp =
        {
                {1000, "M"},
                {900,  "CM"},
                {500,  "D"},
                {400,  "CD"},
                {100,  "C"},
                {90,   "XC"},
                {50,   "L"},
                {40,   "XL"},
                {10,   "X"},
                {9,    "IX"},
                {5,    "V"},
                {4,    "IV"},
                {1,    "I"}
        };

class Solution
{
public:
    string intToRoman(int num)
    {
        string ans;
        for (const auto &[f,s]: mp)
        {
            while (f <= num)
            {
                ans += s;
                num -= f;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.intToRoman(58);
}