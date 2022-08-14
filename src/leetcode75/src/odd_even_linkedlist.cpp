//
// Created by sajith on 8/13/22.
//

#include "base.h"

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *odd = new ListNode;
        ListNode *even = new ListNode;

        if(head->val % 2 == 0)
        {
            even->next = head;
            head = head->next;
            while(head !=nullptr)
            {
                
            }

        }else
        {
            odd->next = head;
        }


    }
};