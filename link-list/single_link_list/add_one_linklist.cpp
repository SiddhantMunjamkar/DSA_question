#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
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
    ListNode *addOne(ListNode *head)
    {
        ListNode *temp = head;
        int ans = 0;
        while (temp != nullptr)
        {
            ans = ans * 10 + temp->val;
            temp = temp->next;
        }
        ans = ans + 1;
        vector<int> v;
        string s = to_string(ans);
        for (char c : s)
        {
            v.push_back(c - '0');
        }

        ListNode *newHead = new ListNode(v[0]);
        ListNode *perv = newHead;
        for (int i = 1; i < v.size(); i++)
        {
            ListNode *front = new ListNode(v[i]);
            perv->next = front;
            perv = front;
        }
        return newHead;
    }
};

int main()
{
    Solution sol;

    vector<int> v = {9, 9};
    ListNode *head = new ListNode(v[0]);
    ListNode *perv = head;
    for (int i = 1; i < v.size(); i++)
    {
        ListNode *front = new ListNode(v[i]);
        perv->next = front;
        perv = front;
    }
    head = sol.addOne(head);

    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
     
    }
       cout << endl;

    int a = 17;
    cout << a / 10 << endl;
    cout << a % 10 << endl;

    return 0;
}