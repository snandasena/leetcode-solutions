//
// Created by sajith on 10/1/22.
//
#include <bits/stdc++.h>

using namespace std;

string res(4, ' ');

void all_subsets(int index)
{
    if (index == res.size())
    {
        cout << res << endl;
        return;
    }

    res[index] = '0';
    all_subsets(index + 1);
    res[index] = '1';
    all_subsets(index + 1);
    res[index] = ' ';
}

int main()
{
    all_subsets(0);
}