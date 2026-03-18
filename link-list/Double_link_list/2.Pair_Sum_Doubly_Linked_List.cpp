#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *perv;
    Node(int x) : val(x), next(NULL), perv(NULL) {}
};

class SOlution
{
public:
    vector<pair<int, int>> pairsum(Node *head, int target)
    {
        vector<pair<int, int>> ans;
        Node *left = head;
        Node *right = head;
        while (right->next != nullptr)
        {
            right = right->next;
        }
        while (left != right && left->next != nullptr)
        {
            int sum = left->val + right->val;
            if (sum == target)
            {
                ans.push_back({left->val, right->val});
                left = left->next;
                right = right->perv;
            }
            else if (sum < target)
            {
                left = left->next;
            }
            else
            {
                right = right->perv;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}