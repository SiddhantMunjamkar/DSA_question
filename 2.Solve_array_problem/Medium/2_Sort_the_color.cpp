#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] > nums[j])
                {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol->sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    delete sol;

    return 0;
}