#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// Problem Statement:
// In a town, there are n people labeled from 1 to n. There is a town judge who trusts nobody and is trusted by everybody.
// You are given trust, an array of pairs trust[i] = [a, b] representing that the person labeled a trusts the person labeled b.
// If the town judge exists and can be identified, return the label of the town judge. Otherwise, return -1.

// Intuition:
// To identify the town judge, we need to find a person who is trusted by all others (except themselves) and trusts nobody.
// We can use two arrays to count the number of people each person trusts and the number of people trusting each person.
// The town judge will be the person who is trusted by n - 1 people and trusts nobody.

// DSA Strategy:
// Counting, Graphs indegree and out degree

// Approach:
// 1. Create two arrays, 'trusts' and 'trustedBy', to count how many people each person trusts and how many people trust each person, respectively.
// 2. Iterate through the 'trust' array and update the counts accordingly.
// 3. Iterate through each person and check if they are trusted by n - 1 people and trust nobody.
// 4. If such a person is found, return their label as the town judge. Otherwise, return -1.

// Time Complexity: O(N + E), where N is the number of people and E is the number of trust relationships.
// Space Complexity: O(N), where N is the number of people.

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> trusts(n + 1, 0);    // Array to count how many people each person trusts
    vector<int> trustedBy(n + 1, 0); // Array to count how many people trust each person

    // Count trust relationships
    for (const auto &t : trust)
    {
        int a = t[0];   // Person labeled ai
        int b = t[1];   // Person labeled bi
        trusts[a]++;    // Person ai trusts person bi
        trustedBy[b]++; // Person bi is trusted by person ai
    }

    // Check for the town judge
    for (int i = 1; i <= n; ++i)
    {
        // Check if person i is trusted by n - 1 people and trusts nobody
        if (trusts[i] == 0 && trustedBy[i] == n - 1)
        {
            return i; // Return the label of the town judge
        }
    }

    return -1; // No town judge found
}

int main()
{
    // Example input
    vector<vector<int>> trust{{1, 3}, {2, 3}};

    // Find the town judge and print their label
    cout << "Town Judge: " << findJudge(3, trust) << endl;
}
