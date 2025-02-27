//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  stack<int>st;
  stack<int>minst;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        st.push(x);
        if(minst.empty() or x<=minst.top()) minst.push(x);
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!st.empty())
        {
            if(st.top()==minst.top()) minst.pop();
             st.pop();
        }
       
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        return st.empty() ? -1 : st.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        return minst.empty() ? -1 : minst.top();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

/*https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1*/ 