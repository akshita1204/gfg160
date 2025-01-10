//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char,int>mp;
        int i=0,j=0,maxlen=0;
        while(j<s.length())
        {
            char ch=s[j];
            if(mp.find(ch)!=mp.end())
            {
               i=max(i,mp[ch]+1);
            }
            mp[ch]=j;
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

/*https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/longest-distinct-characters-in-string5848*/