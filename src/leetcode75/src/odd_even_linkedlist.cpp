//
// Created by sajith on 8/13/22.
//

#include "base.h"

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }

        if (head->next == nullptr || head->next->next == nullptr)
        {
            return head;
        }

        auto *odd = head;
        auto *even = head->next;
        auto *even_final = head->next;

        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = even_final;
        return head;
    }
};