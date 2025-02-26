//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
    vector<int> left(n, -1), right(n, n);
    stack<int> s;

    // Compute Previous Smaller Element (PSE)
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (!s.empty()) left[i] = s.top();
        s.push(i);
    }

    // Clear stack for next use
    while (!s.empty()) s.pop();

    // Compute Next Smaller Element (NSE)
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (!s.empty()) right[i] = s.top();
        s.push(i);
    }

    // Compute the maximum of minimums for every window size
    vector<int> res(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int windowSize = right[i] - left[i] - 1;
        res[windowSize] = max(res[windowSize], arr[i]);
    }

    // Fill the remaining entries in res[] to make it non-decreasing
    for (int i = n - 1; i >= 1; i--) {
        res[i] = max(res[i], res[i + 1]);
    }

    // Return result from index 1 to n
    return vector<int>(res.begin() + 1, res.end());
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

/*https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1*/