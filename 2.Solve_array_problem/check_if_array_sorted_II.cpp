#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkifArraySorted(vector<int> &nums)
    {
        int i = 0;
        int j = i + 1;
        int n = nums.size();
        int count = 0;

        while (j < n)
        {
            if (nums[i] > nums[j])
            {
                count++;
            }
            i++;
            j++;
        }

        if (nums[0] > nums[n - 1])
        {
            count++;
        }
        return count <= 1;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution *obj = new Solution();
    cout << obj->checkifArraySorted(nums) << endl;

    return 0;
}