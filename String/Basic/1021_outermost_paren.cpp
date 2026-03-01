#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string isValid(string s)
    {
        string result;
        int depth = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                if (depth >= 0)
                {
                    result += '(';
                }
                depth++;
            }
            else
            {
                depth--;
                if (depth >= 0)
                {
                    result += ')';
                }
            }
        }
        return result;
    }
};

int main()
{

    return 0;
}