#include <iostream>
#include <vector>
using namespace std;

// Function to reverse a string.
// Intuition:
// - We use two pointers, one pointing to the start of the string and the other pointing to the end.
// - We swap characters at the two pointers and move the pointers towards the center until they meet.
// Approach:
// - Initialize two pointers, 'i' pointing to the start of the string and 'j' pointing to the end.
// - While 'i' is less than 'j', swap the characters at 'i' and 'j' and move 'i' towards the end and 'j' towards the start.
// Time complexity: O(n), where n is the length of the string.
//   - We iterate through half of the string to perform the swap operation.
// Space complexity: O(1), constant space used.
void reverseString(vector<char> &s)
{
    int i = 0, j = s.size() - 1; // Initialize two pointers

    // Iterate until 'i' is less than 'j'
    while (i < j)
    {
        swap(s[i++], s[j--]); // Swap characters at 'i' and 'j', then move pointers
    }
}

int main()
{
    vector<char> s = {'a', 'b', 'c', 'd', 'e'}; // Input string
    reverseString(s); // Reverse the string
    for (char c : s)
    {
        cout << c; // Output the reversed string
    }
    return 0;
}
