//
// Created by sajith on 10/22/22.
//


#include "base.h"

class Solution
{


public:
    string minWindow(string s, string t)
    {
        int left = 0;
        int right = 0;
        int min_len = INT_MAX;
        int min_left = -1;
        int cnt = t.size();

        vector<int> v(58, 0);
        for (const auto &ch: t)
        {
            ++v[ch - 'A'];
        }

        for (; right < s.size(); ++right)
        {
            if (--v[s[right] - 'A'] >= 0)
            {
                --cnt;
            }

            while (cnt == 0)
            {
                if (right - left + 1 < min_len)
                {
                    min_left = left;
                    min_len = right - left + 1;
                }

                if (++v[s[left++] - 'A'] > 0)
                {
                    ++cnt;
                }
            }
        }

        if (min_left == -1)
        {
            return "";
        }
        return s.substr(min_left, min_len);
    }
};

//bool operator<(const vector<int> &a, const vector<int> &b)
//{
//    for (int i = 0; i < a.size(); ++i)
//    {
//        if (a[i] > b[i])
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//int main()
//{
//
//    Solution sol;
//    string s{"abcde"};
////    cout << sol.minWindow("cabefgecdaecf", "cae");
//
//    vector<int> a{1, 2, 3, 4};
//    vector<int> b{2, 3, 4, 1};
//
//    cout << boolalpha << (a < b) << endl;
//}
