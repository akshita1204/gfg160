//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool f(string&s,int i,int j)
  {
      while(i<j)
      {
          if(s[i]!=s[j]) return false;
          i++;
          j--;
      }
      return true;
  }
    string longestPalindrome(string& s) {
        // code here
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                if(f(s,i,j))
                {
                    string t=s.substr(i,j-i+1);
                    ans=t.size()>ans.size()?t:ans;
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

/*https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1*/ 