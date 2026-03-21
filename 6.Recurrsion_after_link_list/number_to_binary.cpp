#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    string binary = "";

    while (n > 0)
    {
        binary = char((n % 2) + '0') + binary;
        n = n / 2;
    }

    cout << binary;
}
