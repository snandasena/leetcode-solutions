//
// Created by sajith on 7/23/22.
//


#include "base.h"

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode{0};
        ListNode *temp = head;

        ListNode *l1 = list1;
        ListNode *l2 = list2;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
            }
        }

        while (l1)
        {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }

        while (l2)
        {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }

        return head->next;
    }
};