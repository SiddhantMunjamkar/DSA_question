#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *back;
};

class Solution
{
public:
    void *DeleteAllOccrence(Node *head, int val)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }

        while (head != nullptr && head->val == val)
        {
            Node *del = head;
            head = head->next;
            if (head->back != nullptr)
            {
                head->back = nullptr;
            }
            delete del;
        }

        Node *temp = head;
        Node *front = temp ? temp->next : nullptr;
        Node *perv = nullptr;
        while (temp != nullptr)
        {
            if (temp->val == val && temp->next != nullptr)
            {
                if (perv != nullptr)
                {
                    perv->next = temp->next;
                }
                temp->next->back = perv;
                Node *del = temp;
                temp = temp->next;
                del->next = nullptr;
                delete del;
            }
            else if (temp->val == val && temp->next == nullptr)
            {
                if (perv != nullptr)
                {
                    perv->next = nullptr;
                }
                perv->next = nullptr;
                delete temp;
                break;
            }
            else
            {
                perv = temp;
                temp = front;
                if (front != nullptr)
                {
                    front = front->next;
                }
            }
        }
    }
};

int main()
{

    return 0;
}