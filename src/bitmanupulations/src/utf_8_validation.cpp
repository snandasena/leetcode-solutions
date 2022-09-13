//
// Created by sajith on 9/13/22.
//


#include "base.h"

class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {

        int mask1 = 1 << 7;
        int mask2 = 1 << 6;
        int mask;
        int num_bits_to_process = 0;
        for (const auto &ele: data)
        {
            if (num_bits_to_process == 0)
            {
                mask = 1 << 7;
                while ((mask & ele) != 0)
                {
                    ++num_bits_to_process;
                    mask >>= 1;
                }

                if (num_bits_to_process == 0)
                {
                    continue;
                }

                if (num_bits_to_process > 4 || num_bits_to_process == 1)
                {
                    return false;
                }
            }
            else
            {
                if (!((ele & mask1) != 0 && (ele & mask2) == 0))
                {
                    return false;
                }
            }

            --num_bits_to_process;
        }
        return num_bits_to_process == 0;
    }
};

int main()
{
    Solution sol;
    vector<int> v{197, 130, 1};
    sol.validUtf8(v);
    return 0;
}