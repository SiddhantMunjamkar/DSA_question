#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void allpossible(vector<int> candidates, int target, vector<vector<int>> &ans, vector<int> curr, int index)
    {
        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            if (candidates[i] > target)
            {
                break;
            }
            curr.push_back(candidates[i]);
            allpossible(candidates, target - candidates[i], ans, curr, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        allpossible(candidates, target, ans, curr, 0);
        return ans;
    }
};

int main()
{
    Solution *obj = new Solution();
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = obj->combinationSum2(candidates, target);
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