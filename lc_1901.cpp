#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxelement(vector<vector<int>> &mat, int m, int n, int mid)
    {
        int maxval = INT_MIN;
        int maxrow = -1;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][mid] > maxval)
            {
                maxval = mat[i][mid];
                maxrow = i;
            }
        }
        return maxrow;
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int r = mat.size();
        int col = mat[0].size();

        int s = 0;
        int e = col - 1;
        while (s <= e)
        {
            int mid = (e - s) / 2 + s;
            int maxrow = maxelement(mat, col, r, mid);
            int left = (mid - 1 >= 0) ? mat[maxrow][mid - 1] : -1;
            int right = (mid + 1 < col) ? mat[maxrow][mid + 1] : -1;

            if (mat[maxrow][mid] > left && mat[maxrow][mid] > right)
            {
                return {maxrow, mid};
            }
            else if (mat[maxrow][mid] < left)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return {-1, -1};
    }
};