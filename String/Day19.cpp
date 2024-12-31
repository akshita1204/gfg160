//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        
        string rev=s;
        reverse(rev.begin(),rev.end());
        string com=s+"$"+rev;
        int n=com.length();
        vector<int>LPS(n,0);
        LPS[0]=0;
        int i=1,len=0;
        while(i<n)
        {
            if(com[i]==com[len])
            {
                len++;
                LPS[i]=len;
                i++;
            }
            else
            {
                if(len!=0) len=LPS[len-1];
                else 
                {
                    LPS[i]=0;
                    i++;
                }
            }
        }
        int ele=LPS[n-1];
        return s.length()-ele;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

/*https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/minimum-characters-to-be-added-at-front-to-make-string-palindrome */