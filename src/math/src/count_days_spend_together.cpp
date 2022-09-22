//
// Created by sajith on 9/22/22.
//
#include "base.h"


unordered_map<string, int> mp = []()
{
    vector<int> months{-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    unordered_map<string, int> m;
    int day = 1;
    for (int i = 1; i <= 12; ++i)
    {
        for (int j = 1; j <= months[i]; ++j)
        {
            string str;
            if (i < 10)
            {
                str += '0' + to_string(i);
            }
            else
            {
                str += to_string(i);
            }
            str += '-';
            if (j < 10)
            {
                str += '0' + to_string(j);
            }
            else
            {
                str += to_string(j);
            }
            m[str] = day;
            ++day;
        }
    }
    return m;
}();

class Solution
{
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        int ai = mp[arriveAlice];
        int ao = mp[leaveAlice];
        int bi = mp[arriveBob];
        int bo = mp[leaveBob];

        if (ai > bo || bi > ao)
        {
            return 0;
        }
        return min(ao, bo) - max(ai, bi) + 1;
    }
};

int main()
{

}