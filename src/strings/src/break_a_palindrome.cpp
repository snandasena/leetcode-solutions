//
// Created by sajith on 10/10/22.
//

#include "base.h"

class Solution
{

public:
    string breakPalindrome(string palindrome)
    {
        if (palindrome.size() == 1)
        {
            return "";
        }

        for (int i = 0; i < palindrome.size() / 2; ++i)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[palindrome.size() - 1] = 'b';
        return palindrome;
    }
};

int main()
{
    Solution sol;

    cout << sol.breakPalindrome("aa");
}