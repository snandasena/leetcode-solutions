//
// Created by sajith on 10/14/22.
//
#include "base.h"

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == nullptr)
        {
            return nullptr;
        }
        ListNode *f = head;
        ListNode *s = head;

        while (f != nullptr && f->next != nullptr)
        {
            f = f->next->next;
            s = s->next;
        }
        if (s->next != nullptr)
        {
            *s = *s->next;
        }
        else
        {
            head->next = nullptr;
        }
        return head;
    }
};

int main()
{
    ListNode *root = new ListNode{1};
    root->next = new ListNode{3};
    root->next->next = new ListNode{4};
    root->next->next->next = new ListNode{7};
    root->next->next->next->next = new ListNode{1};
    root->next->next->next->next->next = new ListNode{2};
    root->next->next->next->next->next->next = new ListNode{6};

    Solution sol;
    sol.deleteMiddle(root);
    return
}