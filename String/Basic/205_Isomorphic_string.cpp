#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        map<char, char> forward;
        map<char, char> backward;
        for (int i = 0; i < s.size(); i++)
        {
            char start = s[i];
            char end = t[i];
            if (forward.count(start))
            {
                if (forward[start] != end)
                {
                    return false;
                }
            }
            else
            {
                forward[start] = end;
            }

            if (backward.count(end))
            {
                if (backward[end] != start)
                {
                    return false;
                }
            }
            else
            {
                backward[end] = start;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}