//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int countWays(string &s) {
        // code here
           int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
        
        // Base case: single character (T or F)
        for (int i = 0; i < n; i += 2) {
            dp[i][i][1] = (s[i] == 'T');  // True
            dp[i][i][0] = (s[i] == 'F');  // False
        }

        // Iterate over substring lengths
        for (int len = 3; len <= n; len += 2) {
            for (int i = 0; i <= n - len; i += 2) {
                int j = i + len - 1;
                dp[i][j][0] = dp[i][j][1] = 0;

                for (int k = i + 1; k < j; k += 2) {  // Iterate over operators
                    int LT = dp[i][k - 1][1], LF = dp[i][k - 1][0];
                    int RT = dp[k + 1][j][1], RF = dp[k + 1][j][0];

                    if (s[k] == '&') {
                        dp[i][j][1] += (LT * RT);  // Only (T & T) is true
                        dp[i][j][0] += (LT * RF) + (LF * RT) + (LF * RF);
                    } 
                    else if (s[k] == '|') {
                        dp[i][j][1] += (LT * RT) + (LT * RF) + (LF * RT);
                        dp[i][j][0] += (LF * RF);  // Only (F | F) is false
                    } 
                    else if (s[k] == '^') {  // XOR case
                        dp[i][j][1] += (LT * RF) + (LF * RT);
                        dp[i][j][0] += (LT * RT) + (LF * RF);
                    }
                }
            }
        }

        return dp[0][n - 1][1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
/*https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1*/