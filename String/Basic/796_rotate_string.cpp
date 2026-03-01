#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        string result;
        for (int i = 0; i < s.size(); i++)
        {
            result = s.substr(i) + s.substr(0, i);
            if (result == goal)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution *solution = new Solution();
    string s = "abcde";
    string goal = "cdeab";
    bool result = solution->rotateString(s, goal);
    cout << result << endl;

    return 0;
}