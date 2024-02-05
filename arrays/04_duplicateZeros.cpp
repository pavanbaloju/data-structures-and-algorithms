#include <iostream>
#include <vector>
using namespace std;

// basic
// Function to duplicate zeros in a given array by shifting elements.
// Interview Revision Notes:
// Approach 1:
// This approach iterates through the array from end to start.
// When encountering a zero, it shifts all elements to the right to make space for duplication.
// Time Complexity: O(n^2), where n is the size of the input array.
// Space Complexity: O(1), no extra space used apart from the input array.

void duplicateZeros(vector<int> &arr)
{
    int count = arr.size(); // Store the size of the array.
    for (int i = count - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
        {
            // Shift elements to the right to make space for duplication.
            for (int j = count - 2; j >= i; j--)
            {
                arr[j + 1] = arr[j];
            }
        }
    }
}

// Function to duplicate zeros in a given array using an auxiliary array.
// Interview Revision Notes:
// Approach 2:
// This approach uses an auxiliary array to store the modified elements.
// It iterates through the input array and duplicates zeros as needed.
// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(n), additional space used for the auxiliary array.

void duplicateZeros2(vector<int> &arr)
{
    vector<int> temp; // Auxiliary array to store modified elements.
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            temp.push_back(0); // Duplicate zero.
            temp.push_back(0);
        }
        else
            temp.push_back(arr[i]); // Copy non-zero element.
    }
    // Copy elements from auxiliary array to original array.
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = temp[i];
    }
}


int main()
{
    vector<int> nums = {1, 0, 2, 3, 0, 4, 5, 0};
    duplicateZeros2(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    return 0;
}