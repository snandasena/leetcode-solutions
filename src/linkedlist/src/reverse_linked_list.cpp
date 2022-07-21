//
// Created by sajith on 3/28/22.
//

#include "base.h"

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        ListNode *prev{nullptr};
        ListNode *curr = head;
        ListNode *next;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
};