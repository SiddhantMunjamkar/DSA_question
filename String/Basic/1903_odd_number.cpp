#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    string oddNumber(string num)
    {
        string result = "";
        for (int i = num.size(); i >= 0; i--)
        {
            if ((num[i] - '0') % 2 != 0)
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main()
{

    return 0;
}