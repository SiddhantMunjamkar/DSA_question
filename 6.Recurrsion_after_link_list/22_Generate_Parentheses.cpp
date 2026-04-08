#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generatePar(int n, int open, int close, string curr, vector<string> &result)
    {
        if (open == n && close == n)
        {
            result.push_back(curr);
            return;
        }
        if (open < n)
        
        
        {
            generatePar(n, open + 1, close, curr + "(", result);
        }

        if (close < open)
        {
            generatePar(n, open, close + 1, curr + ")", result);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generatePar(n, 0, 0, "", result);
        return result;
    }
};

int main()
{
    Solution obj;
    vector<string> result = obj.generateParenthesis(4);
    for (string &s : result)
    {
        cout << s << " ";
    }
    return 0;
}