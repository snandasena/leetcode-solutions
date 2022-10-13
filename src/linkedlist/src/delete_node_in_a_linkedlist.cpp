
//
// Created by sajith on 10/13/22.
//
#include "base.h"

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        *node = *node->next;
    }
};