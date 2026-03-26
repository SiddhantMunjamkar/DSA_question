#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void allposible(string &digits, vector<string> &mpp, vector<string> &ans, int index, string curr)
    {
        if (index == digits.size())
        {
            ans.push_back(curr);
            return;
        }
        string letter = mpp[digits[index] - '0'];
        for (char ch : letter)
        {
            allposible(digits, mpp, ans, index + 1, curr + ch);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }
        vector<string> mpp = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        allposible(digits, mpp, ans, 0, "");
        return ans;
    }
};

int main()
{
    Solution *obj = new Solution();
    string digits = "23";
    vector<string> ans = obj->letterCombinations(digits);
    for (auto i : ans)
    {
        cout << i << ", ";
    }
    return 0;
}