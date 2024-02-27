#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// Problem Statement:
// Given an array 'arr' representing the number of pages in 'n' books and an integer 'm' representing the number of students,
// the task is to allocate the minimum number of pages to each student such that each student gets at least one book and the
// maximum number of pages allocated to a student is minimized.

// Intuition:
// We need to find the minimum number of pages that can be allocated to each student while ensuring that each student receives
// at least one book. Since the goal is to minimize the maximum pages allocated to any student, we can use binary search to
// find the minimum number of pages.

// DSA Strategy:
// Binary Search

// Approach:
// 1. Initialize the range for binary search as [maximum page in books, sum of all pages in books].
// 2. Perform binary search on the range.
// 3. For each mid value, calculate the number of students required to allocate books with maximum pages per student.
// 4. If the number of students is greater than 'm', adjust the range to the right; otherwise, adjust it to the left.
// 5. Continue the binary search until the range converges to a single value.
// 6. Return the minimum number of pages allocated to each student.

// Time Complexity: O(n * log(sum of all pages)), where 'n' is the number of books.
// Space Complexity: O(1).

// Function to count the number of students required to allocate books with maximum pages per student
int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size(); // Number of books
    int students = 1;
    long long pagesStudent = 0;

    // Iterate through the books
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            // Add pages to the current student
            pagesStudent += arr[i];
        }
        else
        {
            // Move to the next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

// Function to find the minimum number of pages allocated to each student using binary search
int findPages(vector<int> &arr, int n, int m)
{
    // If the number of students is greater than the number of books, allocation is impossible
    if (m > n)
        return -1;

    // Initialize the range for binary search
    int low = *max_element(arr.begin(), arr.end());   // Minimum possible pages
    int high = accumulate(arr.begin(), arr.end(), 0); // Maximum possible pages

    // Perform binary search on the range
    while (low <= high)
    {
        int mid = (low + high) / 2;             // Mid value
        int students = countStudents(arr, mid); // Number of students needed for current mid value
        if (students > m)
        {
            // If the number of students is greater than m, increase the pages
            low = mid + 1;
        }
        else
        {
            // If the number of students is less than or equal to m, decrease the pages
            high = mid - 1;
        }
    }
    return low; // Return the minimized maximum number of pages allocated to each student
}

// Main function
int main()
{
    vector<int> arr = {25, 46, 28, 49, 24}; // Array representing the number of pages in each book
    int n = 5;                              // Number of books
    int m = 4;                              // Number of students

    // Output the result of the approach
    cout << "Approach: " << findPages(arr, n, m) << "\n";

    return 0;
}