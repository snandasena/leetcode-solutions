//
// Created by sajit on 03/03/2024.
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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