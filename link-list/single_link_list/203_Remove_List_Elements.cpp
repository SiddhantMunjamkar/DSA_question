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
    ListNode *RemoveElements(ListNode *head, int val)
    {

        if (head == nullptr)
        {
            return head;
        }
        while (head != nullptr && head->val == val)
        {
            ListNode *del = head;
            head = head->next;
            delete del;
        }

        ListNode *temp = head;
        ListNode *perv = nullptr;
        while (temp != nullptr)
        {

            if (temp->val == val && temp->next != nullptr)
            {
                perv->next = temp->next;
                ListNode *del = temp;
                temp = temp->next;
                del->next = nullptr;
                delete del;
            }
            else if (temp->val == val && temp->next == nullptr)
            {
                perv->next = nullptr;
                delete temp;
                break;
            }
            else
            {
                perv = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
int main()
{
    Solution mylist;
    vector<int> arr = {7, 7, 7, 7, 7};
    ListNode *head = new ListNode(arr[0]);
    ListNode *perv = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        perv->next = temp;
        perv = temp;
    }
    head = mylist.RemoveElements(head, 7);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}