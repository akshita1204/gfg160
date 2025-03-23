//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int f(string &digits,int i,vector<int>&dp)
  {
      int n=digits.size();
      if(i==n) return 1;
      if(digits[i]=='0') return 0;
      if(dp[i]!=-1) return dp[i];
      
      //single digit
      int ways=f(digits,i+1,dp);
      if(i+1<n)
      {
          int twodig=stoi(digits.substr(i,2));
          if(twodig>=10 and twodig<=26)
          {
              ways+=f(digits,i+2,dp);
          }
      }
      return dp[i]=ways;
      
      
  }
    int countWays(string &digits) {
        // Code here
        int n=digits.size();
        if(n==0 or digits[0]=='0') return 0;
        vector<int>dp(n,-1);
        return f(digits,0,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
/*https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1*/ 