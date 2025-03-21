//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
  int dp[100001];
  int f(vector<int>&nums,int i)
  {
      if(i==nums.size()-1) return nums[i];
      if(i==nums.size()-2) return max(nums[i],nums[i+1]);
      if(dp[i]!=-1) return dp[i];
      return dp[i]=max(nums[i]+f(nums,i+2),f(nums,i+1));
  }
    // Function to find the maximum money the thief can get.
    int findMaxSum(vector<int>& arr) {
        // Your code here
        memset(dp,-1,sizeof(dp));
        return f(arr,0);
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
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

/*https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1*/