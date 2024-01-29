#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth)
{

    int spacesReq;
    int currLen = 0;

    vector<string> line;
    vector<string> result;

    for (auto &word : words)
    {
        int wordLen = word.size();
        spacesReq = line.size();
        if (currLen + wordLen + spacesReq > maxWidth)
        {
            string answer = "";
            int spaces = maxWidth - currLen;
            if (line.size() == 1)
            {
                answer = line[0];
                while (spaces-- > 0)
                    answer += " ";
                result.push_back(answer);
            }
            else
            {
                int spaceBetween = spaces / (line.size() - 1);
                int extraSpaces = maxWidth - currLen - spaceBetween * (line.size() - 1);
                answer = line[0];
                string bet = "";
                while (spaceBetween-- > 0)
                    bet += " ";
                for (int i = 1; i < line.size(); i++)
                {
                    answer += bet;
                    if (extraSpaces > 0)
                    {
                        answer += " ";
                        extraSpaces -= 1;
                    }
                    answer += line[i];
                }
                result.push_back(answer);
            }
            line.clear();
            currLen = wordLen;
            line.push_back(word);
        }
        else
        {
            currLen += wordLen;
            line.push_back(word);
        }
    }

    if (line.size() >= 1)
    {
        string answer = line[0];
        for (int i = 1; i < line.size(); i++)
        {
            answer += " " + line[i];
        }
        while (answer.size() < maxWidth)
            answer += " ";
        result.push_back(answer);
    }

    return result;
}

int main()
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> lines = fullJustify(words, 16);
    for (string s : lines)
        cout << s << endl;
    return 0;
}