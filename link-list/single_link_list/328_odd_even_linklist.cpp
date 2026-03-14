#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *oddEventLinkList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        vector<int> v;
        vector<int> result;
        while (head->next != nullptr)
        {
            v.push_back(head->val);
            head = head->next;
        }
        // odd(1 ,3, 5)
        for (int i = 0; i < v.size(); i += 2)
        {
            result.push_back(v[i]);
        }
        // even(2, 4)
        for (int i = 1; i < v.size(); i += 2)
        {
            result.push_back(v[i]);
        }

        ListNode *newHead = new ListNode(result[0]);
        ListNode *perv = newHead;
        for (int i = 1; i < result.size(); i++)
        {
            ListNode *temp = new ListNode(result[i]);
            perv->next = temp;
            perv = temp;
        }
        return newHead;
    }

public:
    ListNode *oddEventLinkListdiff(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *odd = head;
        ListNode *even = odd->next;
        ListNode *evenHead = even;
        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

int main()
{

    return 0;
}