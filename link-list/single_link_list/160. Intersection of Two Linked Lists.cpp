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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // your code goes here
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA != pB)
        {
            if (pA == nullptr)
            {
                pA = headB;
            }
            else
            {
                pA = pA->next;
            }
            if (pB == nullptr)
            {
                pB = headA;
            }
            else
            {
                pB = pB->next;
            }
        }
    }
};

int main()
{
    return 0;
}