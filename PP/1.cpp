#include <bits/stdc++.h>
using namespace std;

int maxStopsWithSameParcels(int n, vector<int>& p) {
    unordered_map<int, int> freq;
    vector<int> q(n);
    
    
    for (int i = 0; i < n; ++i) {
        q[i] = n - i;
    }
    
    
    for (int i = 0; i < n; ++i) {
        p[i] += q[i];
        freq[p[i]]++;
    }
    
    
    int max_stops = 0;
    for (const auto& entry : freq) {
        max_stops = max(max_stops, entry.second);
    }
    
    return max_stops;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    
    cout << maxStopsWithSameParcels(n, p) << endl;
    return 0;
}
