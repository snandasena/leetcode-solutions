//
// Created by sajith on 9/4/22.
//

#pragma once

#include <bits/stdc++.h>

#define LOG(x) std::cout<<x
#define END '\n'

using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};