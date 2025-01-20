//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node* reverse(Node* head)
    {
      if(head==NULL) return head;
      Node* cur=head;
      Node* prev=NULL;
      Node* nextnode=NULL;
      while(cur)
      {
          nextnode=cur->next;
          cur->next=prev;
          prev=cur;
          cur=nextnode;
      }
      return prev;
    }
         
    Node *reverseKGroup(Node *head, int k) {
        
        Node* dummy=new Node(-1);
        Node* tem=dummy;
        Node* cur=head;
        
        while(cur)
        {
            int n=k;
            Node* nhead=cur;
            while(cur->next and n>1)
            {
               cur=cur->next;
               n--;
            }
            Node* neigh=cur->next; // neigh=5
            cur->next=NULL; //4->next=NULL
            tem->next=reverse(nhead); // 1 to 4
            
            tem=nhead;
            cur=neigh;
        }
        return dummy->next;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
/*https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/reverse-a-linked-list-in-groups-of-given-size*/