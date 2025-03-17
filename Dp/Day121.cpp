//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{   
public:
vector<vector<int>>dp;
bool f(vector<int>&arr, int k,int i,int n)
{
 if(k==0) return true;
 if(i==n or k<0) return false ;
 if(dp[i][k]!=-1) return dp[i][k];
 bool nt=f(arr,k,i+1,n);
 bool t=false;
 if(arr[i]<=k)  t=f(arr,k-arr[i],i+1,n);
 return dp[i][k]= nt or t;
 
}
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
      dp.clear();
      dp.resize(n,vector<int>(sum+1,-1));
      return f(arr,sum,0,n);
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

/*https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1*/