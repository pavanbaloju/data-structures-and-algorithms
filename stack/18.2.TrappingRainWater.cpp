#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    if (n <= 2)
        return 0; // No water can be trapped if there are less than 3 bars

    stack<int> stk; // Stack to store indices of bars
    int water = 0;  // Variable to store trapped water

    // Iterate through each bar
    for (int i = 0; i < n; ++i)
    {
        while (!stk.empty() && height[i] > height[stk.top()])
        {
            // While the stack is not empty and the current bar's height is greater than the height of the bar at the top of the stack
            int top = stk.top();
            stk.pop(); // Pop the top bar from the stack
            if (!stk.empty())
            {
                // If the stack is not empty after popping the top bar
                int distance = i - stk.top() - 1;                                    // Calculate the distance between the current bar and the bar at the top of the stack
                int boundedHeight = min(height[i], height[stk.top()]) - height[top]; // Calculate the height of water trapped between the two bars
                water += distance * boundedHeight;                                   // Add the trapped water to the total
            }
        }
        stk.push(i); // Push the index of the current bar onto the stack
    }

    return water;
}

int main()
{
    // Example heights of bars
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Calculate the amount of water trapped
    int trappedWater = trap(height);

    // Print the result
    cout << "Amount of water trapped: " << trappedWater << endl;

    return 0;
}
