//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  vector<vector<int>> dp;
    bool isPalindrome(string &s, int i, int j) {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j]; 
        if (s[i] == s[j]) {
            if (j - i == 1) dp[i][j] = 1; 
            else dp[i][j] = isPalindrome(s, i + 1, j - 1);
            } 
        else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }
    int countPS(string &s) {
        int n=s.length();
        if(n<2) return 0;
        dp.assign(n, vector<int>(n, -1)); 
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPalindrome(s, i, j)) count++;
            }
        }
        return count;
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
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
//https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1