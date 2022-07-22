//
// Created by sajith on 7/22/22.
//


#include "base.h"

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *l1 = new ListNode{0};
        ListNode *l2 = new ListNode{0};

        ListNode *before = l1;
        ListNode *after = l2;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                before->next = head;
                before = before->next;
            }
            else
            {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        after->next = nullptr;
        before->next = l2->next;
        return l1->next;
    }
};