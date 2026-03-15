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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *temp = head;
        vector<int> v;
        while (temp != nullptr)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(), v.end());
        ListNode *newHead = new ListNode(v[0]);
        ListNode *perv = newHead;
        for (int i = 1; i < v.size(); i++)
        {
            ListNode *temp = new ListNode(v[i]);
            perv->next = temp;
            perv = temp;
        }
        return newHead;
    }
    // In-place merge sort for linked list
    ListNode* mergeSortList(ListNode* head) {
        if (!head || !head->next) return head;
        // Find the middle
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        // Sort each half
        ListNode* left = mergeSortList(head);
        ListNode* right = mergeSortList(mid);
        // Merge sorted halves
        return mergeTwoLists(left, right);
    }

    // Helper to merge two sorted lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
}

;

int main()
{
    return 0;
}