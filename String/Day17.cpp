//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        unordered_map<char, int> freq;

        // Count the frequency of each character in the string
        for (char c : s) {
            freq[c]++;
        }

        // Traverse the string again and find the first non-repeating character
        for (char c : s) {
            if (freq[c] == 1) {
                return c;  // Return the first non-repeating character
            }
        }

        // If no non-repeating character is found, return '$'
        return '$';
        
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/non-repeating-character-1587115620
*/ 