//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<vector<int>>dp;
  int f(vector<int>&coin,int sum,int idx)
  {
       if(sum==0) return 1;
      if(idx>=coin.size() or sum<0) return 0;
      if(dp[sum][idx]!=-1) return dp[sum][idx];
      //take
      int take=f(coin,sum-coin[idx],idx);
      int skip=f(coin,sum,idx+1);
      return dp[sum][idx]=take+skip;
      
  }
    int count(vector<int>& coins, int sum) {
        // code here.
        dp.resize(sum+1,vector<int>(coins.size(),-1));
        return f(coins,sum,0);
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

/*https://www.geeksforgeeks.org/problems/coin-change2448/1*/