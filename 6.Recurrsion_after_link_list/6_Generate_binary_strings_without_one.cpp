#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate(int n, string curr, vector<string> &ans)
    {
        // base case if length is n, add the ans;
        if (curr.size() == n)
        {
            ans.push_back(curr);
            return;
        }

      

         // add 1 only if last char is not 1
        if (curr.empty() || curr.back() != '1')
        {
            generate(n, curr + '1', ans);
        }

        
          // always try adding 0
        generate(n, curr + '0', ans);
    }
};

int main()
{

    // Input length n
    int n = 3;

    // Vector to store results
    vector<string> result;
    Solution obj;

    // Start recursion with empty string
    obj.generate(n, "", result);

    // Print results
    for (string &s : result)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;

    return 0;
}