#include <bits/stdc++.h>
using namespace std;

// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.

// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int val) : data(val), next(nullptr) {}
    ListNode(int val, ListNode *next1) : data(val), next(next1) {}
};

class Solution
{
public:
    ListNode *newHead(ListNode *head, int cnt)
    {
        while (cnt > 0 && head != nullptr)
        {
            head = head->next;
            cnt--;
        }
        return head;
    }
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int cnt = 0;
        while (temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }
        int middle = cnt / 2;
        return newHead(head, middle);
    }
};

int main()
{
    return 0;
}