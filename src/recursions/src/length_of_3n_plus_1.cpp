//
// Created by sajith on 9/30/22.
//


#include "base.h"

int length_3n_plus_1(int n)
{
    cout << n << '\t';
    if (n == 1)
    {
        return 1;
    }

    if (n % 2 == 0)
    {
        return 1 + length_3n_plus_1(n / 2);
    }

    return 1 + length_3n_plus_1(3 * n + 1);
}

int main()
{

    auto res = length_3n_plus_1(6);
    cout<<endl<<res;
}