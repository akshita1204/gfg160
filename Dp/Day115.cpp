//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<int>dp;
  int f(int i,int n)
  {
      if(i==n) return 1;
      if(i>n) return 0;
      if(dp[i]!=-1) return dp[i];
      int ways=0;
      ways+=f(i+1,n)+f(i+2,n);
      return dp[i]=ways;
  }
    // Function to count number of ways to reach the nth stair.
    int countWays(int n) {
        // your code here
        dp.resize(n+1,-1);
        return f(0,n);
    }
};




//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

/*https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1*/