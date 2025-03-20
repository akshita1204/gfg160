//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
          int n = prices.size();
        if (n < 2) return 0;

        vector<int> profit_left(n, 0);  // Max profit in first transaction
        vector<int> profit_right(n, 0); // Max profit in second transaction
        
        // Left to Right Pass (First Transaction)
        int min_price = prices[0];
        for (int i = 1; i < n; i++) {
            min_price = min(min_price, prices[i]);
            profit_left[i] = max(profit_left[i - 1], prices[i] - min_price);
        }

        // Right to Left Pass (Second Transaction)
        int max_price = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            max_price = max(max_price, prices[i]);
            profit_right[i] = max(profit_right[i + 1], max_price - prices[i]);
        }

        // Find the maximum sum of both transactions
        int max_profit = 0;
        for (int i = 0; i < n; i++) {
            max_profit = max(max_profit, profit_left[i] + (i + 1 < n ? profit_right[i + 1] : 0));
        }

        return max_profit;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

/*https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1*/