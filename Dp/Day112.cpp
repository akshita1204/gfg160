//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  vector<vector<int>>dp;
  int f(int i,int j,string&s)
  {
      if(i>j) return 0;
      if(i==j) return 1;
     if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
     if(s[i]==s[j])
     {
        return dp[i][j]=2+f(i+1,j-1,s);
     }
     return dp[i][j]=max(f(i+1,j,s),f(i,j-1,s));
  }
  
    int longestPalinSubseq(string &s) {
        // code here
        int n=s.length();
        dp.resize(n,vector<int>(n,-1));
        return f(0,n-1,s);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

/*https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1*/ 