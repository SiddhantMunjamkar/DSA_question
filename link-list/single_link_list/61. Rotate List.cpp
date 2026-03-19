#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    Node *rotateRight(Node *head, int k)
    {
        if (head == nullptr || k == 1)
        {
            return head;
        }
        Node *temp = head;
        int n = 0;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            n++;
        }
        k = k % n;
        int steps = n - k;
        Node *Newtail = head;
        for (int i = 1; i < steps; i++)
        {
            Newtail = Newtail->next;
        }
        Node *newhead = Newtail->next;
        Newtail->next = nullptr;

        return newhead;
    }
};

int main()
{
    return 0;
}