//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int findParent(int x, vector<int> &parent) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent); // Path compression
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
               int n = deadline.size();
        vector<pair<int, int>> jobs;
        
        // Step 1: Pair deadlines with profits
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        
        // Step 2: Sort jobs by descending order of profit
        sort(jobs.rbegin(), jobs.rend());
        
        // Step 3: Find the maximum deadline
        int maxDeadline = 0;
        for (auto &job : jobs) {
            maxDeadline = max(maxDeadline, job.second);
        }
        
        // Step 4: Create a Disjoint Set (DSU) to track free slots
        vector<int> parent(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }
        
        int jobCount = 0, totalProfit = 0;
        
        // Step 5: Process jobs in order of profit
        for (auto &job : jobs) {
            int p = job.first;
            int d = job.second;
            
            int availableSlot = findParent(d, parent);
            if (availableSlot > 0) { // If there's a free slot available
                parent[availableSlot] = findParent(availableSlot - 1, parent); // Merge sets
                totalProfit += p;
                jobCount++;
            }
        }
        
        return {jobCount, totalProfit};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1