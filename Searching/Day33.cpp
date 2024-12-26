//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
bool canplace(vector<int>&s,int dis,int cows)
{
    int c=1;
    int last=s[0];
    for(int i=1;i<s.size();i++)
    {
        if(s[i]-last>=dis)
        {
            c++;
            last=s[i];
        }
        if(c>=cows) return true;
    }
    return false;
}
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int low=0, high=stalls[n-1]-stalls[0];
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(canplace(stalls,mid,k)==true) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/aggressive-cows
*/ 