#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;
    bool visited = false;
    string word;
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }

    bool isVisited()
    {
        return visited;
    }

    void setVisited()
    {
        visited = true;
    }

    void setWord(string &word)
    {
        this->word = word;
    }
};
class Solution
{
private:
    Node *root;

public:
    Solution()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
        node->setWord(word);
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool find(int br, int bc, int ind, vector<vector<char>> &board, Node *node, vector<string> &ans)
    {
        if (br < 0 || br >= board.size() || bc < 0 || bc >= board[0].size() || board[br][bc] == 'X')
            return false;

        char ch = board[br][bc];
        node = node->get(ch);
        if (node == nullptr)
            return false;

        if (node->isEnd() && !node->isVisited())
        {
            ans.push_back(node->word);
            node->setVisited();
        }

        bool exists = false;
        board[br][bc] = 'X';
        exists = exists || find(br - 1, bc, ind + 1, board, node, ans);
        exists = exists || find(br + 1, bc, ind + 1, board, node, ans);
        exists = exists || find(br, bc - 1, ind + 1, board, node, ans);
        exists = exists || find(br, bc + 1, ind + 1, board, node, ans);
        board[br][bc] = ch;
        return exists;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> ans;
        for (string word : words)
            insert(word);

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                find(i, j, 0, board, root, ans);
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<char>> board{{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words{"oath", "pea", "eat", "rain"};

    vector<string> ans = Solution().findWords(board, words);
    for (string s : ans)
        cout << s << endl;

    return 0;
}