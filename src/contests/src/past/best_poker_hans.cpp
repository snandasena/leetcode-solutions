//
// Created by sajith on 7/23/22.
//


#include "../base.h"

class Solution
{
public:
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        sort(suits.begin(), suits.end());
        if (suits[0] == suits.back()) return "Flush";

        sort(ranks.begin(), ranks.end());
        if (ranks[0] == ranks[2] || ranks[1] == ranks[3] || ranks[2] == ranks[4]) return "Three of a Kind";

        if (ranks[0] == ranks[1] || ranks[1] == ranks[2] || ranks[2] == ranks[3] || ranks[3] == ranks[4]) return "Pair";

        return "High Card";
    }
};