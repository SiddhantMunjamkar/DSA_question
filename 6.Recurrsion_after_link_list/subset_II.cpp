#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void allpossible(vector<int> nums, vector<int> curr, vector<vector<int>> &ans, int index)
    {
        if (index == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        allpossible(nums, curr, ans, index + 1);
        curr.pop_back();
        int i = index;
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
        {
            i++;
        }
        allpossible(nums, curr, ans, i + 1);
    }
    vector<vector<int>> subsets(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        allpossible(nums, curr, ans, 0);
        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = sol->subsets(nums);
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