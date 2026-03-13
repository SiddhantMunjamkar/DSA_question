
// Input: head -> 1 -> 2 -> 3 -> 4 -> 5, pos = 1

// Output: 4

// Explanation: 2 -> 3 -> 4 -> 5 - >2, length of loop = 4.

// Example 2

// Input: head -> 1 -> 3 -> 7 -> 4, pos = -1

// Output: 0

// Explanation: No loop is present in the linked list.

#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution
{
public:
    int findLengthOfLoop(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        int count = 0;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            count++;
            if (slow == fast)
            {
                return count;
            }
        }
        return 0;
    }
};