#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t reverse = 0;
    for (int i = 0; i < 32; i++)
    {
        reverse <<= 1;
        reverse += n % 2;
        n >>= 1;
    }
    return reverse;
}

int main()
{
    cout << reverseBits(43261596) << endl;
    return 0;
}