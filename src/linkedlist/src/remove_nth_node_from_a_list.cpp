//
// Created by sajith on 9/28/22.
//

#include "base.h"


class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *ans = new ListNode;
        ans->next = head;
        ListNode *curr = head;
        int t = 0;
        while (curr != nullptr)
        {
            curr = curr->next;
            ++t;
        }
        curr = ans;
        t -= n;
        while (t-- > 0)
        {
            curr = curr->next;
        }
        curr->next = curr->next->next;

        return ans->next;
    }
};