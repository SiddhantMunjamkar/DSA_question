#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> arr;
        while (head != nullptr)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        int start = 0;
        int end = arr.size() - 1;
        while (start < end)
        {
            if (arr[start] != arr[end])
            {
                return false;
            }
            start++;
            end--;
        }
    }

public:
    bool isPalindrome(ListNode *head)
    {
    }
};

int main()
{
    Solution sol;
    return 0;
}