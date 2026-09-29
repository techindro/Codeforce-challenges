#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
 
    map<int, vector<int>> adj;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    int start = -1;
    for (auto& pair : adj) {
        if (pair.second.size() == 1) {
            start = pair.first;
            break;
        }
    }
 
    vector<int> route;
    int curr = start;
    int prev = -1;
 
    while (curr != -1) {
        route.push_back(curr);
        int next_city = -1;
        for (int neighbor : adj[curr]) {
            if (neighbor != prev) {
                next_city = neighbor;
                break;
            }
        }
        prev = curr;
        curr = next_city;
    }
 
    for (size_t i = 0; i < route.size(); ++i) {
        cout << route[i] << (i + 1 == route.size() ? "" : " ");
    }
    cout << "
";
 
    return 0;
}