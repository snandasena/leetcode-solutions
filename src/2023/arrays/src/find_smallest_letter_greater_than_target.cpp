#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        if(letters.back() <= target )
            return letters[0];

        return *find_if(letters.cbegin(), letters.cend(), [&target](auto c)
        {
            return c > target;
        });
    }
};

int main()
{
    Solution sol;
    vector<char> v{{'c', 'f', 'j'}};
    cout << sol.nextGreatestLetter(v, 'a');
}