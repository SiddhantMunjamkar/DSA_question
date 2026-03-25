
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void allpossible(vector<int> &nums, vector<int> curr,
                     vector<vector<int>> &ans, int index)
    {

        if (index == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        allpossible(nums, curr, ans, index + 1);
        curr.pop_back();
        allpossible(nums, curr, ans, index + 1);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        allpossible(nums, curr, ans, 0);
        return ans;
    }
};

int main()
{
    return 0;
}
