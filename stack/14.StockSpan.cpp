#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Problem Statement:
// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock
// and we need to calculate the span of stock's price for all n days. The span of the stock's price on a given
// day i is defined as the maximum number of consecutive days (starting from today and going backward) for which
// the stock price was less than or equal to the current day's price.

// Intuition:
// We can solve this problem efficiently using a stack data structure. We iterate through the stock prices,
// and for each price, we maintain a stack that stores the indices of previous stock prices where the price
// was less than or equal to the current price. The span of the current day's price is then calculated as the
// difference between the current index and the index of the previous smaller or equal price.

// DSA Strategy:
// Stack

// Approach:
// 1. Create a stack to store the indices of previous stock prices and a vector to store the spans.
// 2. Iterate through the stock prices:
//    a. While the stack is not empty and the price at the top of the stack is less than or equal to
//       the current price, pop elements from the stack.
//    b. Calculate the span as the difference between the current index and the index of the previous
//       smaller or equal price in the stack. If the stack is empty, the span is the current index + 1.
//    c. Push the current index onto the stack.
// 3. Return the vector of spans.

// Time Complexity: O(n), where n is the number of stock prices.
// Space Complexity: O(n), where n is the number of stock prices (for the stack and vector).

// Function to calculate stock spans for given stock prices
vector<int> stockSpan(vector<int> &stockPrices)
{
    stack<int> st;
    vector<int> span(stockPrices.size(), 0); // Vector to store stock spans

    // Iterate through stock prices
    for (int i = 0; i < stockPrices.size(); i++)
    {
        // Pop elements from stack until a greater element is found or stack is empty
        while (!st.empty() && stockPrices[st.top()] <= stockPrices[i])
        {
            st.pop();
        }

        // Calculate span as difference between current index and index of top of stack
        span[i] = st.empty() ? i + 1 : i - st.top();

        // Push current index onto stack
        st.push(i);
    }
    return span; // Return vector of stock spans
}

// Function to print elements of a vector
void printVector(vector<int> &v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

// Class to dynamically calculate stock spans
class StockSpanner
{
    stack<pair<int, int>> st; // Stack to store pairs of (price, span)
public:
    StockSpanner()
    {
        st = stack<pair<int, int>>(); // Initialize stack
    }

    // Method to calculate stock span for next stock price
    int next(int price)
    {
        int span = 1;

        // Add spans of previous days with prices less than or equal to current price
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }

        // Push current price and calculated span onto stack
        st.push({price, span});

        return span; // Return calculated span
    }
};

int main()
{
    // Example usage
    vector<int> stockPrices = {100, 80, 60, 70, 60, 75, 85};

    // Calculate and print stock spans using function
    vector<int> span = stockSpan(stockPrices);
    cout << "Stock spans using function: ";
    printVector(span);

    // Calculate and print stock spans using class
    StockSpanner *ss = new StockSpanner();
    cout << "Stock spans using class: ";
    cout << ss->next(100) << " ";
    cout << ss->next(80) << " ";
    cout << ss->next(60) << " ";
    cout << ss->next(70) << " ";
    cout << ss->next(60) << " ";
    cout << ss->next(75) << " ";
    cout << ss->next(85) << endl;

    return 0;
}
