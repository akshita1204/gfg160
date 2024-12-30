//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int maxlen=0;
        unordered_set<int>st;
        for(int ele:arr) st.insert(ele);
        for(int ele:st)
        {
            //if it is the first element
            if(st.find(ele-1)==st.end())
            {
                int curele=ele;
                int c=1;
                while(st.find(curele+1)!=st.end())
                {
                    c++;
                    curele=curele+1;
                }
                maxlen=max(maxlen,c);
            }
        }
        return maxlen;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/longest-consecutive-subsequence2449
*/