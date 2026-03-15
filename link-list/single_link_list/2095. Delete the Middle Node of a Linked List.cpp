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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == nullptr)
        {
            return nullptr;
        }

        ListNode *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        int mid = count / 2;
        int element = 0;
        ListNode *last = head;
        ListNode *perv = nullptr;
        while (element != mid)
        {
            perv = last;
            last = last->next;
            element++;
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