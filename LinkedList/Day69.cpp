//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node* rev(Node* head)
  {
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
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        int carry=0;
        Node* head=new Node(0);
        Node* prev=head;
        Node* n1=rev(num1);
        Node* n2=rev(num2);
        while(n1!=NULL || n2!=NULL || carry)
        {
            int a=0;
            int b=0;
            if(n1!=NULL)
            {
                a=n1->data;
                n1=n1->next;
            }
            if(n2!=NULL)
            {
                b=n2->data;
                n2=n2->next;
            }
            int sum=a+b+carry;
            carry=sum/10;
            prev->next=new Node(sum%10);
            prev=prev->next;
           
          
        }
        Node* result = rev(head->next);
        Node* current = result;
        //to remove the leading zero
        while (current != NULL && current->data == 0) {
          current = current->next;
          }
      //if all nodes are zero
      if (current == NULL) {
          return new Node(0);
      }

      return current;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

/*https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/add-two-numbers-represented-by-linked-lists*/