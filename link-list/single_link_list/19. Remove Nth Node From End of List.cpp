#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp->next != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (count == n)
        {
            ListNode *del = head;
            head->next;
            delete del;
            return head;
        }
        ListNode *last = head;
        ListNode *perv = nullptr;
        while (count != n)
        {
            perv = last;
            last = last->next;
            count--;
        }
        perv->next = last->next;
        delete last;
        return head;
    }
};

int main()
{
    return 0;
}