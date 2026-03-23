#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void gettingallsubsets(string s, vector<string> &ans, string curr, int index)
    {
        if (index == s.size())
        {
            ans.push_back(curr);
            return;
        }

        gettingallsubsets(s, ans, curr + s[index], index + 1);
        gettingallsubsets(s, ans, curr, index + 1);
    }
    vector<string> powerset(string s)
    {
        vector<string> ans;
        gettingallsubsets(s, ans, "", 0);

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<string> ans = obj.powerset("abc");
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}