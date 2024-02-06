#include <iostream>
#include <vector>
using namespace std;

// Function to print elements of a vector.
// Intuition:
// We iterate through the vector and print each element separated by a space.
// Time complexity: O(n), where n is the size of the input vector.
// Space complexity: O(1), no extra space used besides variables.
void print(vector<int> arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// Function to find disappeared numbers in an array.
// Disappeared numbers are the numbers that are missing from a given range of consecutive integers within an array.
// Intuition:
// We traverse the array and mark each number's corresponding index (minus one) as negative.
// Then, we iterate through the array again and add the indices of positive numbers to the result vector.
// These indices correspond to numbers that did not appear in the array.
// Time complexity: O(n), where n is the size of the input array.
// Space complexity: O(1), no extra space used besides variables.
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int n = nums.size(); // Number of elements in the array
    // Mark each number's corresponding index as negative
    for (int i = 0; i < n; i++)
    {
        int value = abs(nums[i]); // Absolute value of the current number
        int index = value - 1;     // Index corresponding to the current number
        if (nums[index] > 0)      // If the number at the index is positive
        {
            nums[index] = nums[index] * -1; // Mark it as negative
        }
    }
    vector<int> res; // Result vector to store disappeared numbers
    // Iterate through the array again to find positive numbers (indices of disappeared numbers)
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0) // If the number is positive
        {
            res.push_back(i + 1); // Add its index (plus one) to the result vector
        }
    }
    return res; // Return the result vector containing disappeared numbers
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1}; // Example array
    vector<int> res = findDisappearedNumbers(nums); // Find disappeared numbers
    print(res); // Print the disappeared numbers
    return 0;
}
