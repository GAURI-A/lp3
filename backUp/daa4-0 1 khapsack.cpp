#include <iostream>
#include <vector>
using namespace std;

int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;  // Number of items
    int capacity;  // Knapsack capacity

    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weights of items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values of items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int maxValue = knapsack(capacity, weights, values, n);

    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}
