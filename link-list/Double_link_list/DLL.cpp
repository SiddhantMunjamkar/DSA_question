#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Forward declaration
Node *insertNode(Node *head, int val);

Node *convertArrToDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node *DeleteHead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return NULL;
    }
    Node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node *DeleteTail(Node *head)
{
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node *newtail = tail->back;
    newtail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node *DeleteKthNode(Node *head, int k)
{
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;

    if (prev == nullptr && front == nullptr)
    {
        return NULL;
    }
    else if (prev == nullptr)
    {
        return DeleteHead(head);
    }
    else if (front == nullptr)
    {
        return DeleteTail(head);
    }

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void DeleteNode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == nullptr)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;

    free(temp);
}

Node *insertBeforetail(Node *head, int val)
{
    if (head->next == nullptr)
    {
        return insertNode(head, val);
    }

    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;

    Node *newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

Node *insertNode(Node *head, int val)
{
    Node *newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;
}

Node *insertBeforeKthElement(Node *head, int val, int k)
{
    if (k == 1)
    {
        return insertNode(head, val);
    }
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArrToDLL(arr);
    // head = DeleteHead(head);
    // head = DeleteTail(head);
    // head = DeleteKthNode(head, 4);
    // DeleteHead(head->next);
    head = insertBeforeKthElement(head, 10, 3);
    print(head);
    return 0;
}