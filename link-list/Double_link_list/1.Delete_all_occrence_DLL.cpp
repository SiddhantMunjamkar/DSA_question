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
    Node *DeleteAllOccrence(Node *head, int val)
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
    }
};

int main()
{

    return 0;
}