#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ispalindrome(string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--])
            {
                return false;
            }
        }
        return true;
    }
    void ispossible(string &s, vector<vector<string>> &ans, vector<string> &curr, int index)
    {
        if (index == s.size())
        {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            if (ispalindrome(s, index, i))
            {
                curr.push_back(s.substr(index, i - index + 1));
                ispossible(s, ans, curr, i + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> curr;
        ispossible(s, ans, curr, 0);
        return ans;
    }
};


int main()
{
    Solution obj;
    string s = "ab";
    vector<vector<string>> ans = obj.partition(s);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << ", ";
        }
        cout << endl;
    }

    return 0;
}
