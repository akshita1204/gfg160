//{ Driver Code Starts
    #include <bits/stdc++.h>
    using namespace std;
    
    
    // } Driver Code Ends
    
    class Solution {
      public:
      vector<vector<int>>dp;
      int f(int w,vector<int>&val,vector<int>&wt,int n)
      {
          if(n==0 or w==0) return 0;
          if(dp[n][w]!=-1) return dp[n][w];
          if (wt[n - 1] > w) return dp[n][w] = f(w, val, wt, n - 1);
          return dp[n][w]=max(f(w,val,wt,n-1), val[n-1]+f(w-wt[n-1],val,wt,n-1));
      }
        // Function to return max value that can be put in knapsack of capacity.
        int knapsack(int W, vector<int> &val, vector<int> &wt) {
            // code here
            int n = val.size();
            dp.resize(n + 1, vector<int>(W + 1, -1));
            return f(W, val, wt, n);
            
        }
    };
    
    
    //{ Driver Code Starts.
    
    int main() {
        // Taking total test cases
        int testCases;
        cin >> testCases;
        cin.ignore();
        while (testCases--) {
            // Reading number of items and capacity
            int numberOfItems, capacity;
            vector<int> weights, values;
            string input;
            int number;
    
            // Read capacity and number of items
            getline(cin, input);
            stringstream ss(input);
            ss >> capacity;      // The first number is the capacity
            ss >> numberOfItems; // The second number is the number of items
    
            // Read values
            getline(cin, input);
            ss.clear();
            ss.str(input);
            while (ss >> number) {
                values.push_back(number);
            }
    
            // Read weights
            getline(cin, input);
            ss.clear();
            ss.str(input);
            while (ss >> number) {
                weights.push_back(number);
            }
    
            Solution solution;
            cout << solution.knapsack(capacity, values, weights) << endl;
            cout << "~" << endl;
        }
        return 0;
    }
    
    /*https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1*/ 