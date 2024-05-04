//
// Created by sajit on 01/05/2024.
//
#include "base.h"


class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        unsigned i = 0;
        string str;
        while (i < word.size())
        {
            if (word[i] == ch)
            {
                str = word[i] + str;
                return str + word.substr(i+1);
            }

            str = word[i] + str;
            ++i;
        }

        return word;
    }
};

int main()
{

    Solution sol;
    cout << sol.reversePrefix("abcdef", 'f');
    return 0;
}