#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int power(int x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n < 0)
        {
            return 1 / (x * power(x, -(n + 1)));
        }
        int half = power(x, n / 2);
        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }
};

int main()
{
    return 0;
}