#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> result;
        stringstream ss(s);
        string ans;
        while (ss >> s)
        {
            result.push_back(s);
        }

        for (int i = result.size() - 1; i >= 0; i++)
        {
            ans += result[i];
            if (i != 0)
            {
                ans += " ";
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}