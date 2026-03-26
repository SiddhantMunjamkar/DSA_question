#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void allpossible(vector<int> &nums, int target, vector<vector<int>> &ans, vector<int> curr, int index, int k)
    {
        if (target == 0 && k == 0)
        {
            ans.push_back(curr);
            return;
        }
        if (index == nums.size() || target < 0 || k < 0)
        {
            return;
        }
        curr.push_back(nums[index]);
        allpossible(nums, target - nums[index], ans, curr, index + 1, k - 1);
        curr.pop_back();
        allpossible(nums, target, ans, curr, index + 1, k);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> v;
        for (int i = 1; i <= 9; i++)
        {
            v.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> curr;
        allpossible(v, n, ans, curr, 0, k);
        return ans;
    }
};

int main()
{
    Solution *obj = new Solution();
    int k = 3;
    int n = 7;
    vector<vector<int>> ans = obj->combinationSum3(k, n);
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