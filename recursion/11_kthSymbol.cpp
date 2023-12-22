#include <iostream>
using namespace std;

/*
        0
    0       1
0      1 1     0
*/

int kthGrammar(int N, int K)
{
    if (N == 1)
        return 0;
    if (K % 2 == 0)
        return !kthGrammar(N - 1, K / 2);
    else
        return kthGrammar(N - 1, (K + 1) / 2);
}

int main()
{
    cout << kthGrammar(3, 3) << endl;
    return 0;
}