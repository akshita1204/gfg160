//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int merge(vector<int>&a,int low,int mid,int high)
  {
      int l=low;
      int r=mid+1;
      int c=0;
      vector<int>v;
      while(l<=mid and r<=high)
      {
          if(a[l]<=a[r])
          {
              v.push_back(a[l]);
              l++;
          }
          else //right is smalller
          {
              v.push_back(a[r]);
              c+=(mid-l+1);
              r++;
          }
      }
      //if elements on the left are still left
      while(l<=mid)
      {
          v.push_back(a[l]);
          l++;
      }
      //if elements on the right are still left
      while(r<=high)
      {
          v.push_back(a[r]);
          r++;
      }
      //transfer back the elements
      for(int i=low;i<=high;i++)
      {
          a[i]=v[i-low];
      }
      return c;
  }
  
  int mergesort(vector<int>&a,int low,int high)
  {
      int c=0;
      if(low>=high) return c;
      int mid=(low+high)/2;
      c+=mergesort(a,low,mid);
      c+=mergesort(a,mid+1,high);
      c+=merge(a,low,mid,high);
      return c;
  }
  
  
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        return mergesort(arr,0,n-1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

/*
https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/inversion-of-array-1587115620
*/