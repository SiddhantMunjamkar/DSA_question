#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mpp;

        for (auto it : nums)
        {
            mpp[it]++;
        }

        int maxi = 0;
        int count = 0;

        for (auto it : mpp)
        {
            if (it.second > count)
            {
                count = it.second;
                maxi = it.first;
            }
        }

        return maxi;
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<int> nums = {3, 2, 3};
    int ans = sol->majorityElement(nums);
    cout << ans << endl;
    delete sol;

    return 0;
}