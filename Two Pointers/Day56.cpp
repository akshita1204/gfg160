//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int sum=0;
        int i=0,j=0;
        int n=arr.size();
        vector<int>ans;
        while(j<n)
        {
            sum+=arr[j];
            int rem=target-sum;
             while(sum>target and i<=j)
             {
                 sum-=arr[i];
                 i++;
             }
            if(sum==target)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            j++;
        }
        return {-1};
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/subarray-with-given-sum-1587115621
*/