#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortedInsert(stack<int> &s, int val)
    {
        if (s.empty() || s.top() > val)
        {
            s.push(val);
            return;
        }
        int top = s.top();
        s.pop();
        sortedInsert(s, val);
        s.push(top);
    }
    void sortstack(stack<int> &s)
    {

        if (s.empty())
        {
            return;
        }

        int top = s.top();
        s.pop();
        sortstack(s);
        sortedInsert(s, top);
    }
};

int main()
{
    Solution obj;
    stack<int> s;
    s.push(41);
    s.push(32);
    s.push(23);
    s.push(12);
    s.push(11);
    s.push(13);
    s.push(14);
    s.push(15);
    obj.sortstack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}