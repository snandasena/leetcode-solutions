//
// Created by sajith on 7/23/22.
//


#include "base.h"

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) break;
        }

        if (fast == nullptr || fast->next == nullptr) return nullptr;

        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};