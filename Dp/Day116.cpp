//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
  vector<int>dp;
  int f(int i,int n,vector<int>& cost)
  {
      if(i>=n) return 0;
      if(dp[i]!=-1) return dp[i];
      return dp[i]=min(cost[i]+f(i+1,n,cost),cost[i]+f(i+2,n,cost));
  }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n=cost.size();
        dp.resize(n+1,-1);
        return min(f(0,n,cost),f(1,n,cost));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
/*https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1*/