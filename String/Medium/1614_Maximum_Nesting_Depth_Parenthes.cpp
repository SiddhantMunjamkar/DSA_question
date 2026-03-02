

#include <bits/stdc++.h>
using namespace std;

class Soultion
{
public:
    int maDepth(string s)
    {
        int depth = 0;
        int ans = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                depth++;
            }
            else
            {
                ans = max(ans, depth);
                if (depth > 0 && c == ')')
                {
                    depth--;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Soultion sol;
    string s = "(1+(2*3)+((8)/4))+1";
    cout << sol.maDepth(s) << endl;

    return 0;
}