//
// Created by sajit on 15/08/2023.
//

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *l1 = new ListNode{0};
        ListNode *l2 = new ListNode{0};

        ListNode *before = l1;
        ListNode *after = l2;

        while (head)
        {
            if (head->val < x)
            {
                before->next = head;
                before = before->next;
            } else
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