//
// Created by sajit on 08/04/2023.
//

#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
        {
            return node;
        }
        unordered_map<Node *, Node *> graph;
        graph[node] = new Node{node->val};

        queue<Node *> que;
        que.push(node);
        Node *head;
        while (!que.empty())
        {
            head = que.front();
            que.pop();

            for (const auto neighbor: head->neighbors)
            {
                if (graph.find(neighbor) == graph.end())
                {
                    graph[neighbor] = new Node{neighbor->val};
                    que.push(neighbor);
                }
                graph[head]->neighbors.push_back(graph[neighbor]);
            }
        }
        return graph[node];
    }
};