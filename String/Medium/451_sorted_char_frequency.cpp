#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string frequencyword(string s)
    {
        map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }
        priority_queue<pair<int, char>> pq;

        for (auto &it : freq)
        {
            pq.push({it.second, it.first});
        }
        string answer;
        while (!pq.empty())
        {
            pair<int, char> top = pq.top();
            pq.pop();
            answer += string(top.first, top.second);
        }
        return answer;
    }
};

int main()
{

    Solution sol;
    string s = "tree";
    cout << sol.frequencyword(s) << endl;
    return 0;
}