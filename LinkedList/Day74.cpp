//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  int capacity;
  list<pair<int,int>>dq;
  unordered_map<int,list<pair<int,int>>::iterator>map;
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        capacity=cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(map.find(key)==map.end()) return -1;
        dq.splice(dq.begin(),dq,map[key]);
        return map[key]->second;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(map.find(key)!=map.end())
        {
            dq.splice(dq.begin(),dq,map[key]);
            map[key]->second=value;
            return;
        }
        if(dq.size()==capacity)
        {
            int lrukey=dq.back().first;
            dq.pop_back();
            map.erase(lrukey);
        }
        dq.push_front({key,value});
        map[key]=dq.begin();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

/https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/lru-cache/ } Driver Code Ends