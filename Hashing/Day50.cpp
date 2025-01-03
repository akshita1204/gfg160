//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>mp;
        int exor=0,c=0;
        mp[exor]++;
        for(int i=0;i<arr.size();i++)
        {
           exor=exor^arr[i];
           int x=exor^k;
           c+=mp[x];
           mp[exor]++;
           
        }
        return c;
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/count-subarray-with-given-xor
*/