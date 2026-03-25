#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void targetcombinationsum(vector<int> candidates, int target, vector<vector<int>> &ans, vector<int> curr, int index)
    {
        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }
        if (index == candidates.size() || target < 0)
        {
            return;
        }
        curr.push_back(candidates[index]);
        targetcombinationsum(candidates, target - candidates[index], ans, curr, index);
        curr.pop_back();
        targetcombinationsum(candidates, target, ans, curr, index + 1);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        targetcombinationsum(candidates, target, ans, curr, 0);
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans = obj.combinationSum(candidates, target);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
