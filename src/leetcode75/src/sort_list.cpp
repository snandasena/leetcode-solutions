//
// Created by sajith on 8/15/22.
//
#include "base.h"


class Solution
{
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = new ListNode{0};
        ListNode *curr = ptr;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1 != nullptr)
        {
            curr->next = l1;
        }

        if (l2 != nullptr)
        {
            curr->next = l2;
        }
        return ptr->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {

        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp{nullptr};

        while (fast != nullptr && fast->next != nullptr)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return merge(l1, l2);
    }
};

int main()
{

    ListNode *root = new ListNode{-1};
    root->next = new ListNode{5};
    root->next->next = new ListNode{3};
    root->next->next->next = new ListNode{4};
    root->next->next->next->next = new ListNode{0};

    Solution sol;
    sol.sortList(root);

    return 0;
}