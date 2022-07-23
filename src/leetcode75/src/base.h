//
// Created by sajith on 7/21/22.
//

#ifndef LEETCODE_BASE_H
#define LEETCODE_BASE_H

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


#endif //LEETCODE_BASE_H
