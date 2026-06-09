#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> printSubarrayMaxSum(vector<int> &nums)
    {
        long long currSum = 0;
        long long maxSum = 0;
        vector<int> curr;
        vector<int> ans;

        for (int x : nums)
        {
            // [1,2,5]
            // [2,6]
            if (x >= 0)
            {
                currSum += x;
                curr.push_back(x);
            }
            else
            {
                if (currSum > maxSum || (currSum == maxSum && curr.size() > ans.size()))
                {
                    maxSum = currSum;
                    ans = curr;
                }
                currSum = 0;
                curr.clear();
            }
            //  comparing the [1,2,5] and [2,3] subarrays
            if (currSum > maxSum || (currSum == maxSum && curr.size() > ans.size()))
            {
                maxSum = currSum;
                ans = curr;
            }
        }
        if (ans.empty())
        {
            return {-1};
        }
        return ans;
    }
};

int main()
{

    Solution *sol = new Solution();
    vector<int> nums = {1, 2, 5, -7, 2, 3};
    vector<int> ans = sol->printSubarrayMaxSum(nums);
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}