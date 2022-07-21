//
// Created by sajith on 7/21/22.
//


#include "base.h"

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *dummy = new ListNode{0};
        dummy->next = head;
        ListNode *curr = dummy;
        ListNode *prev{nullptr};

        for (int i = 0; i < left; ++i)
        {
            prev = curr;
            curr = curr->next;
        }

        ListNode *currR = curr;
        ListNode *prevR = prev;
        ListNode *next;
        for (int i = left; i <= right; ++i)
        {
            next = currR->next;
            currR->next = prevR;
            prevR = currR;
            currR = next;
        }

        prev->next = prevR;
        curr->next = currR;
        return dummy->next;
    }
};