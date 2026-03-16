#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *&head)
    {
        // your code goes here
        vector<int> v;
        while (head != nullptr)
        {
            v.push_back(head->data);
            head = head->next;
        }
        sort(v.begin(), v.end());

        ListNode *newHead = new ListNode(v[0]);
        ListNode *perv = newHead;
        for (int i = 1; i < v.size(); i++)
        {
            ListNode *temp = new ListNode(v[i]);
            perv->next = temp;
            perv = temp;
        }
        return newHead;
    }
    ListNode *sortListzeroandones(ListNode *head)
    {
        ListNode *zero = new ListNode(-1);
        ListNode *one = new ListNode(-1);
        ListNode *two = new ListNode(-1);

        ListNode *zeroTail = zero;
        ListNode *oneTail = one;
        ListNode *twoTail = two;

        ListNode *curr = head;
        while (curr != nullptr)
        {
            if (curr->data == 0)
            {
                zeroTail->next = curr;
                zeroTail = curr;
            }
            else if (curr->data == 1)
            {
                oneTail->next = curr;
                oneTail = curr;
            }
            else if (curr->data == 2)
            {
                twoTail->next = curr;
                twoTail = curr;
            }
            curr = curr->next;
        }
        zeroTail->next = one->next ? one->next : two->next;
        oneTail->next = two->next;
        twoTail->next = nullptr;

        return zero->next;
    }
};

int main()
{
    return 0;
}
