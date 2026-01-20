#include <bits/stdc++.h>

using namespace std;

bool is_possible(vector<int> &arr, int n, int, int mid)
{
    int numberofStudents = 1;
    int studentpages = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (studentpages + arr[i] <= mid)
        {
            studentpages += arr[i];
        }
        else
        {
            numberofStudents++;
            if (numberofStudents > n || arr[i] > mid)
            {
                return false;
            }
            studentpages = arr[i];
        }
    }
    return numberofStudents <= n;
}

int book_allocation_problem(int n, int m, vector<int> arr)
{
    int s = 0;
    int e = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (s < e)
    {

        int mid = s + (e - s) / 2;

        if (is_possible(arr, n, m, s))
        {

            ans = e;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n = 4; // number of students
    int m = 5; // number of books
    vector<int> arr = {25, 46, 28, 49, 24};

    cout << book_allocation_problem(n, m, arr) << endl;

    return 0;
}