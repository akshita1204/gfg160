//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<vector<int>>dp;
  int f(string &a,string &b,int i,int j)
  {
      
      if(i==a.length()) return b.length()-j;
      if(j==b.length()) return a.length()-i;
      if(dp[i][j]!=-1) return dp[i][j];
      //insertion
      if(a[i]==b[j]) return dp[i][j]=f(a,b,i+1,j+1);
      int ins=1+f(a,b,i,j+1);
      int rem=1+f(a,b,i+1,j);
      int rep=1+f(a,b,i+1,j+1);
      return dp[i][j]=min({ins,rem,rep});
      
  }
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        dp.resize(s1.length(),vector<int>(s2.length(),-1));
        return f(s1,s2,0,0);
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

/*https://www.geeksforgeeks.org/problems/edit-distance3702/1*/