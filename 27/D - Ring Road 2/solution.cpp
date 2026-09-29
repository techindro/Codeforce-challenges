#include <bits/stdc++.h>
using namespace std;
 
int n, m;
vector<pair<int,int>> roads;
vector<vector<int>> adj;
vector<int> color;
 
bool intersect(int i, int j) {
    int a = roads[i].first, b = roads[i].second;
    int c = roads[j].first, d = roads[j].second;
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return (a < c && c < b && b < d) || (c < a && a < d && d < b);
}
 
int main() {
    cin >> n >> m;
    roads.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> roads[i].first >> roads[i].second;
    }
    
    adj.assign(m, {});
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if (intersect(i, j)) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
    
    color.assign(m, -1);
    for (int i = 0; i < m; i++) {
        if (color[i] != -1) continue;
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    cout << "Impossible";
                    return 0;
                }
            }
        }
    }
    
    for (int i = 0; i < m; i++)
        cout << (color[i] == 0 ? 'i' : 'o');
    cout << endl;
    return 0;
}