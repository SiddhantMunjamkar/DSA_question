// The statement you mentioned:

// Use two pointers: slow (1 step) and fast (2 steps). If a cycle exists, they will eventually meet.

// This technique is called Floyd’s Cycle Detection Algorithm, also known as the Tortoise and Hare algorithm.

// It appears many times in DSA problems, especially with linked lists or sequences.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}