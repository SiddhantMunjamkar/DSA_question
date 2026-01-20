#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int solve(vector<int> &cookies, vector<int> &ans, int i, int k)
    {
        // base case
        if (i == cookies.size())
        {
            int answer = 0;
            for (auto it : ans)
            {
                answer = max(answer, it);
            }
            return answer;
        }

        int mn = INT_MAX;
        for (int j = 0; j < k; j++)
        {
            ans[j] += cookies[i];
            mn = min(mn, solve(cookies, ans, i + 1, k));
            ans[j] -= cookies[i];
        }

        return mn;
    }

    int distributeCookies(vector<int> &cookies, int k)
    {
        int i = 0;
        vector<int> ans(k, 0);
        return solve(cookies, ans, i, k);
    }
};

int main()
{
    return 0;
}