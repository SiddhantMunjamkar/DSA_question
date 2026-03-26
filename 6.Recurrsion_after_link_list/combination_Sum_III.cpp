#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void allpossible(vector<int> &v, vector<vector<int>> &ans, vector<int> curr,
                     int index, int element, int target)
    {
        if (target == 0 && element == 0)
        {
            ans.push_back(curr);
            return;
        }
        if (index == v.size() || target < 0 || element < 0)
        {
            return;
        }
        curr.push_back(v[index]);
        allpossible(v, ans, curr, index + 1, element - 1, target - v[index]);
        curr.pop_back();

        allpossible(v, ans, curr, index + 1, element, target);
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
        allpossible(v, ans, curr, 0, k, n);
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