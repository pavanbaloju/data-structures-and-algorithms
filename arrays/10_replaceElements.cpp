#include <iostream>
#include <vector>
using namespace std;

// Replace Elements with Greatest Element on Right Side
// Intuition:
// Iterate through the array from right to left.
// Keep track of the greatest element seen so far from the right side.
// Update each element with the greatest element seen so far.
// Approach:
// - Start iterating from the end of the array.
// - Initialize the greatest element as the last element of the array.
// - For each element from right to left:
//     - Update the current element with the greatest element seen so far.
//     - Update the greatest element if the current element is greater.
// Time complexity: O(n) where n is the size of the array.
// Space complexity: O(1) as no extra space is used.
vector<int> replaceElementsWithGreatest(vector<int> &arr)
{
    int n = arr.size();
    int currentGreatest;
    int greatestToRight = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > greatestToRight)
        {
            currentGreatest = arr[i];
        }
        arr[i] = greatestToRight;
        greatestToRight = currentGreatest;
    }

    return arr;
}

int main()
{
    vector<int> arr = {17, 18, 5, 4, 6, 1};

    // Replace elements with the greatest element on the right side
    arr = replaceElementsWithGreatest(arr);

    // Print the modified array
    for (int num : arr)
        cout << num << " ";
    return 0;
}
