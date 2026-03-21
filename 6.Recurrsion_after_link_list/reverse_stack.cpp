#include <bits/stdc++.h>
using namespace std;

class SOlution
{
public:
    void reverseStack(stack<int> &st, int n)
    {
        if (st.empty())
        {
            st.push(n);
            return;
        }

        int top = st.top();
        st.pop();

        reverseStack(st, n);
        st.push(top);
    }

    void reserve(stack<int> &st)
    {
        if (st.empty())
        {
            return;
        }
        int top = st.top();
        st.pop();

        reserve(st);

        reverseStack(st, top);
    }
};

int main()
{
    return 0;
}