//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  vector<vector<int>>dp;
   bool f(vector<int>&v,int sum,int i)
  {
      if(sum==0) return true;
      if(i>=v.size()) return false;
      if(dp[sum][i]!=-1) return dp[sum][i];
      int ans=0;
      if(v[i]<=sum) //include or exclude
      {
          ans=f(v,sum-v[i],i+1) or f(v,sum,i+1);
      }
      else ans=f(v,sum,i+1);
      return dp[sum][i]=ans;
  }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=0;
        for(int i=0;i<arr.size();i++) sum+=arr[i];
        if(sum%2!=0) return false;
        dp.resize(sum+1,vector<int>(arr.size()+1,-1));
        return f(arr,sum/2,0);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
/*https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1*/ 