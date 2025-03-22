//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<int>dp;
  int f(vector<int>&nums)
  {
      int n=nums.size();
      dp[0]=nums[0];
      dp[1]=max(nums[0],nums[1]);
      for(int i=2;i<nums.size();i++)
      {
          dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
      }
      return dp[n-1];
  }
    int maxValue(vector<int>& arr) {
        // your code hre
        int n=arr.size();
        dp.resize(n+1,-1);
        if(n==1) return arr[0];
        if(n==2) return max(arr[0],arr[1]);
        vector<int>a(arr.begin()+1,arr.end());
        vector<int>b(arr.begin(),arr.end()-1);
        return max(f(a),f(b));
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

/*https://www.geeksforgeeks.org/problems/house-robber-ii/1*/