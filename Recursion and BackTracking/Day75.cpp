//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void f(string &s,string &cur,vector<string>&ans,vector<bool>&vis) {
      if(cur.length()==s.length())
      {
          ans.push_back(cur);
          return;
      }
      for(int i=0;i<s.length();i++)
      {
          if(vis[i]) continue;
          if(i>0 and s[i]==s[i-1] and !vis[i-1]) continue;
          vis[i]=true;
          cur.push_back(s[i]);
          f(s,cur,ans,vis);
          cur.pop_back();
          vis[i]=false;
      }
      
  }
    vector<string> findPermutation(string &s) {
        vector<string>ans;
        string cur="";
        vector<bool>vis(s.length(),false);
        sort(s.begin(),s.end());
        f(s,cur,ans,vis);
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
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

/https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/permutations-of-a-given-string2041/ } Driver Code Ends