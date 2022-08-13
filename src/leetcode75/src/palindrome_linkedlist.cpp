//
// Created by sajith on 8/13/22.
//
#include "base.h"

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head) return false;
        if (!head->next) return true;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = slow->next;

        stack<int> s;
        while (slow)
        {
            s.push(slow->val);
            slow = slow->next;
        }

        while (!s.empty())
        {
            int x = s.top();
            if (head->val != x) return false;
            s.pop();
            head = head->next;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    ListNode *root = new ListNode{1};
    root->next = new ListNode{1};
    root->next->next = new ListNode{2};

    sol.isPalindrome(root);

    return 0;
}