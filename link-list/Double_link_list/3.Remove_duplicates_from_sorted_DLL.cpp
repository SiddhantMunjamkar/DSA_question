#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *perv;
    Node(int x)
    {
        data = x;
        next = NULL;
        perv = NULL;
    }
};

class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        set<int> s;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (s.count(temp->data))
            {

                Node *del = temp;
                if (temp->perv)
                {
                    temp->perv->next = temp->next;
                }
                else
                {
                    head = temp->next;
                }
                if (temp->next)
                {
                    temp->next->perv = temp->perv;
                }
                temp = temp->next;
                delete del;
            }
            else
            {
                s.insert(temp->data);
                temp = temp->next;
            }
        }
        return head;
    }
};

int main()
{
    return 0;
}