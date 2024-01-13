#include <iostream>
#include <vector>
using namespace std;

bool solve(int br, int bc, int wi, vector<vector<char>> &board, string &word, vector<vector<bool>> &visited)
{
    if (wi == word.size())
        return true;

    if (br < 0 || br >= board.size() || bc < 0 || bc >= board[0].size() || visited[br][bc] || board[br][bc] != word[wi])
        return false;

    bool exists = false;
    visited[br][bc] = true;
    for (auto [nr, nc] : vector<pair<int, int>>({{-1, 0}, {1, 0}, {0, -1}, {0, 1}}))
    {
        exists = exists || solve(br + nr, bc + nc, wi + 1, board, word, visited);
    }
    visited[br][bc] = false;
    return exists;
}

bool exist(vector<vector<char>> &board, string word)
{
    vector<vector<bool>> visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == word[0])
            {
                if (solve(i, j, 0, board, word, visited))
                    return true;
            }
        }
    }
    return false;
}

bool solve2(int br, int bc, int wi, vector<vector<char>> &board, string &word)
{
    if (wi == word.size())
        return true;

    if (br < 0 || br >= board.size() || bc < 0 || bc >= board[0].size() || board[br][bc] == 'X' || board[br][bc] != word[wi])
        return false;

    bool exists = false;
    char ch = board[br][bc];
    board[br][bc] = 'X';
    exists = exists || solve2(br - 1, bc, wi + 1, board, word);
    exists = exists || solve2(br + 1, bc, wi + 1, board, word);
    exists = exists || solve2(br, bc - 1, wi + 1, board, word);
    exists = exists || solve2(br, bc + 1, wi + 1, board, word);
    board[br][bc] = ch;
    return exists;
}

// optimized visited array
bool exist2(vector<vector<char>> &board, string word)
{
    vector<vector<bool>> visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == word[0])
            {
                if (solve2(i, j, 0, board, word))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << exist(board, word) << endl;
    cout << exist2(board, word) << endl;
    return 0;
}