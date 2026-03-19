#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
    
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(NULL) {}

    // Insert at beginning
    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at specific position (1-indexed)
    void insertAtPosition(int val, int pos)
    {
        if (pos == 1)
        {
            insertAtBeginning(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Invalid position!" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from beginning
    void deleteFromBeginning()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd()
    {
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // Delete at specific position (1-indexed)
    void deleteAtPosition(int pos)
    {
        if (head == NULL)
            return;
        if (pos == 1)
        {
            deleteFromBeginning();
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL)
            return;
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Search for a value
    bool search(int val)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Get length
    int getLength()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Reverse the linked list
    void reverse()
    {
        Node *prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Display the linked list
    void display()
    {
        Node *temp = head;
        cout << "List: ";
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~LinkedList()
    {
        Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList list;

    cout << "=== Insertion Operations ===" << endl;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();

    list.insertAtBeginning(5);
    list.display();

    list.insertAtPosition(15, 3);
    list.display();

    cout << "\n=== List Properties ===" << endl;
    cout << "Length: " << list.getLength() << endl;
    cout << "Search 15: " << (list.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (list.search(100) ? "Found" : "Not Found") << endl;

    cout << "\n=== Deletion Operations ===" << endl;
    list.deleteFromBeginning();
    list.display();

    list.deleteFromEnd();
    list.display();

    list.deleteAtPosition(2);
    list.display();

    cout << "\n=== Reverse Operation ===" << endl;
    list.reverse();
    list.display();

    return 0;
}
