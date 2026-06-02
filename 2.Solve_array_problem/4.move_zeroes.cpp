#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int write = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[write] = nums[i];
            write++;
        }
    }
    for (int i = write; i < nums.size(); i++)
    {
        nums[i] = 0;
    }
}

int main()
{

    return 0;
}