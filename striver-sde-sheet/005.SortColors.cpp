#include <iostream>
#include <vector>
using namespace std;

// Function to perform counting sort on the given vector of integers representing colors.
void countSort(vector<int> &colors)
{
    const int NUM_COLORS = 3;                   // Number of colors: red, white, blue.
    vector<int> colorCounts(NUM_COLORS + 1, 0); // Array to store frequency of each color.

    // Step 1: Count the frequency of each color.
    for (int color : colors)
    {
        colorCounts[color]++;
    }

    // Step 2: Calculate the starting index for each color in the sorted array.
    int startIndex = 0;
    for (int color = 0; color <= NUM_COLORS; color++)
    {
        int count = colorCounts[color];
        colorCounts[color] = startIndex;
        startIndex += count;
    }

    // Step 3: Place the colors in the sorted order using colorCounts array.
    vector<int> sortedColors(colors.size()); // Initialize the sorted array.
    for (int color : colors)
    {
        sortedColors[colorCounts[color]] = color;
        colorCounts[color]++;
    }

    // Step 4: Copy the sorted array back to the original array.
    colors = sortedColors;
}

// Function to sort colors (0: red, 1: white, 2: blue) using counting sort.
void sortColors(vector<int> &colors)
{
    countSort(colors);
}

// Function to perform Dutch National Flag algorithm to sort an array of 0s, 1s, and 2s.
// Intuition:
// The Dutch National Flag algorithm is used to sort an array containing 0s, 1s, and 2s by partitioning it into three sections: 0s, 1s, and 2s.
// It does this in a single pass through the array, moving elements into the correct section while maintaining the relative order of elements.
//
// Approach:
// - We initialize three pointers: 'low', 'mid', and 'high'.
// - 'low' points to the first position of the array where we can place 0s.
// - 'mid' is the current position being processed.
// - 'high' points to the last position of the array where we can place 2s.
// - We traverse the array using the 'mid' pointer:
//   - If the element at 'mid' is 0, we swap it with the element at 'low', increment both 'low' and 'mid'.
//   - If the element at 'mid' is 1, we simply increment 'mid'.
//   - If the element at 'mid' is 2, we swap it with the element at 'high', decrement 'high'.
// - We repeat this process until 'mid' crosses 'high', ensuring that all elements are sorted.
//
// Parameters:
// - nums: Reference to the vector containing the array of 0s, 1s, and 2s to be sorted.
void dutchNationalFlag(vector<int> &nums)
{
    int n = nums.size();                // Number of elements in the array
    int low = 0, mid = 0, high = n - 1; // Pointers for low, mid, and high positions

    // Traverse the array until mid crosses high (mid to high is unsorted)
    while (mid <= high)
    {
        if (nums[mid] == 0)
        { // If element at mid is 0, swap it with element at low
            swap(nums[mid], nums[low]);
            low++; // Move low pointer to the right
            mid++; // Move mid pointer to the right
        }
        else if (nums[mid] == 1)
        { // If element at mid is 1, move mid pointer to the right
            mid++;
        }
        else
        { // If element at mid is 2, swap it with element at high
            swap(nums[mid], nums[high]);
            high--; // Move high pointer to the left
        }
    }
}


// Function to print the elements of an array
void printArray(vector<int> &nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    vector<int> colors = {2, 0, 2, 1, 1, 0}; // Input vector representing colors: red, white, blue
    sortColors(colors);                      // Sort the colors
    printArray(colors);                      // Print the original array

    vector<int> nums = {2, 0, 2, 1, 1, 0}; // Input array containing 0s, 1s, and 2s
    cout << "Original Array: ";
    printArray(nums);        // Print the original array
    dutchNationalFlag(nums); // Sort the array using Dutch National Flag algorithm
    cout << "Sorted Array: ";
    printArray(nums); // Print the sorted array
    return 0;
}
