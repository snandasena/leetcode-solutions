//
// Created by sajith on 8/13/22.
//


#include "base.h"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = new ListNode;
        temp->next = head;

        int len = 0;
        ListNode *first = head;
        while (first != nullptr)
        {
            ++len;
            first = first->next;
        }
        len -= n;
        first = temp;

        while (len-- > 0)
        {
            first = first->next;
        }
        first->next = first->next->next;
        return temp->next;
    }
};

