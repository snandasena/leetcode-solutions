//
// Created by sajith on 8/23/22.
//

#include "base.h"


class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;
        stack<int> st;
        while (slow != nullptr)
        {
            st.push(slow->val);
            slow = slow->next;
        }
        while (!st.empty())
        {
            if (head->val != st.top())
            {
                return false;
            }
            st.pop();
            head = head->next;
        }
        return true;
    }
};