#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numbSubseq(vector<int> arr, int target)
    {
        int n = arr.size();
        vector<int> v;
        int mod = 1e9 + 7;
        v[0] = 1;
        for (int i = 1; i < n; i++)
        {
            v[i] = (v[i - 1] * 2) % mod;
        }
        sort(arr.begin(), arr.end());

        int right = n - 1;
        int left = 0;
        int count = 0;
        while (left <= right)
        {
            if (arr[left] + arr[right] <= target)
            {
                count = (count + v[right] - v[left]) % mod;
                left++;
            }
            else
            {
                right--;
            }
        }
        return count;
    }
};
int main()
{
    return 0;
}