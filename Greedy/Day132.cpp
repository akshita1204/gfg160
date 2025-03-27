//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &end) {
        // Your code here
        int n=start.size();
        vector<pair<int,int>>act;
        for(int i=0;i<n;i++)
        {
            act.push_back({end[i],start[i]});
        }
        //sort the activites on the basis of the end time
        sort(act.begin(),act.end());
        int c=1;// one activity will be selected
        int lastend=act[0].first;
        for(int i=1;i<n;i++)
        {
            if(act[i].second >lastend)
            {
                c++;
                lastend=act[i].first;
            }
        }
        return c;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
/*https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1*/