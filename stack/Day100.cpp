//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        // code here
        stack<int>st;
        st.push(-1);
        int maxi=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push(i);
            else st.pop();
            
            if(st.empty()) st.push(i);
            else maxi=max(maxi,i-st.top());
        }
        return maxi;
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
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
/*https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/longest-valid-parentheses5657*/ 