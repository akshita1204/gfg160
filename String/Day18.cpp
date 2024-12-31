//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void findLPS(string&pat,vector<int>&LPS,int m)
  {
      int length=0;//length of previous longest prefix 
      int i=1;
      LPS[0]=0; 
      while(i<m)
      {
          if(pat[i]==pat[length])
          {
              length++;
              LPS[i]=length;
              i++;
          }
          else
          {
              if(length!=0) length=LPS[length-1];
              else 
              {
                  LPS[i]=0;
                  i++;
              }
          }
      }
  }
  
    vector<int> search(string& pat, string& txt) {
     int n=txt.length();
     int m=pat.length();
     vector<int>res; //to store the idx
     //calculate the LPS ie. longest Prefix Suffix
     vector<int>LPS(m,0);
     findLPS(pat,LPS,m);
     //compute the KMP
     int i=0,j=0;
     while(i<n)
     {
         if(txt[i]==pat[j])
         {
             i++;
             j++;
         }
         if(j==m) 
        {
         res.push_back(i-m);
         j=LPS[j-1];
        }
        else if(txt[i]!=pat[j])
        {
            if(j!=0) j=LPS[j-1];
            else i++;
        }
     }
     return res;
     
     
     
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/search-pattern0205
*/