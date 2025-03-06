//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int dp[1001][1001];
  int f(string &a,string &b,int i,int j)
  {
      if(i>=a.length() or j>=b.length()) return 0;
      if(dp[i][j]!=-1) return dp[i][j];
      //if match dono ko badhao
      int ans=0;
      if(a[i]==b[j]) ans=1+f(a,b,i+1,j+1);
      else ans=max(f(a,b,i+1,j),f(a,b,i,j+1));
      return dp[i][j]=ans;
  }
    int lcs(string &s1, string &s2) {
        // code here
        memset(dp,-1,sizeof(dp));
       return f(s1,s2,0,0);
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

/*https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1*/ 