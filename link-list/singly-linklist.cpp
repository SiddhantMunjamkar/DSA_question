#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteValue(Node *&head, int val)
{
    if (!head)
        return;
    if (head->data == val)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    Node *temp = head;
    while (temp->next && temp->next->data != val)
        temp = temp->next;
    if (temp->next)
    {
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    printList(head); // Output: 10 20 30
    deleteValue(head, 20);
    printList(head); // Output: 10 30
    return 0;
}