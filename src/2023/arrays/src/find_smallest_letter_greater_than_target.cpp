#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        auto res = find_if(letters.cbegin(), letters.cend(), [&target](auto c)
        {
            return c > target;
        });
        if (res != letters.cend())
            return *res;
        else
            return letters[0];
    }
};

int main()
{
    Solution sol;
    vector<char> v{{'c', 'f', 'j'}};
    cout << sol.nextGreatestLetter(v, 'a');
}