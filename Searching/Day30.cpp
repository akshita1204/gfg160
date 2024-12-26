//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
int f(vector<int>& nums, int k)
{
    int low=0;
    int high=nums.size()-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==k) ans= mid;
        //if left part is sorted
        if(nums[low]<=nums[mid])
        {
            if(nums[low]<=k and k<=nums[mid])
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        else //right part is sorted
        {
       if(nums[mid]<=k and k<=nums[high])
       {
        low=mid+1;
       }
       else high=mid-1;
        }
    }
    return ans;
}
    int search(vector<int>& arr, int key) {
        // complete the function here
        int ans=f(arr,key);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/search-in-a-rotated-array4618
*/ 