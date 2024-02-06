#include <iostream>
#include <vector>
using namespace std;

// Function to move all zeroes to the end of the array while maintaining the order of non-zero elements.
void moveZeroes(vector<int> &nums)
{
    // Two-pointer approach: i for iterating through the array, j for placing non-zero elements.
    int i = 0, j = 0, n = nums.size();

    while (i < n)
    {
        // If the current element is non-zero, move it to the position indicated by j.
        if (nums[i] != 0)
        {
            nums[j] = nums[i];
            j++;
        }
        i++;
    }

    // Fill the remaining positions with zeroes.
    while (j < n)
    {
        nums[j++] = 0;
    }
}

int main()
{
    vector<int> arr = {0, 1, 0, 3, 12};

    // Move zeroes to the end of the array.
    moveZeroes(arr);

    // Output the modified array.
    for (int a : arr)
        cout << a << " ";

    return 0;
}
