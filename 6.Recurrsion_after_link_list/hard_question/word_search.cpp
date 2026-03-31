#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ispossible(vector<vector<char>> &board, string word, int i, int j, int index)
    {
        if (index == word.size())
        {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index])
        {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';
        bool found = ispossible(board, word, i + 1, j, index + 1) || ispossible(board, word, i - 1, j, index + 1) || ispossible(board, word, i, j + 1, index + 1) || ispossible(board, word, i, j - 1, index + 1);

        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (ispossible(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution obj;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    bool ans = obj.exist(board, word);
    if (ans)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}