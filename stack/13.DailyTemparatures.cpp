#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate the daily temperatures
vector<int> dailyTemperatures(const vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> result(n, 0); // Vector to store the result
    stack<int> stk;           // Stack to store the indices of temperatures

    // Iterate through the temperatures
    for (int i = 0; i < n; ++i)
    {
        // For each temperature, check if there are warmer temperatures waiting to be processed
        // If the current temperature is greater than the temperature at the index on the top of the stack,
        // calculate the number of days until the next warmer temperature
        while (!stk.empty() && temperatures[i] > temperatures[stk.top()])
        {
            int prevIndex = stk.top();         // Get the index of the previously stored temperature
            stk.pop();                         // Pop the previous index from the stack
            result[prevIndex] = i - prevIndex; // Calculate the number of days until the warmer temperature
        }
        // Push the current index onto the stack
        stk.push(i);
    }

    return result;
}

int main()
{
    // Example temperatures: [73, 74, 75, 71, 69, 72, 76, 73]
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    // Calculate the daily temperatures
    vector<int> result = dailyTemperatures(temperatures);

    // Print the daily temperatures
    cout << "Daily temperatures: ";
    for (int temp : result)
    {
        cout << temp << " ";
    }
    cout << endl;

    return 0;
}
