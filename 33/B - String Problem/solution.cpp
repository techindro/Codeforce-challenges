#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int INF = 1e9;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s, t;
    if (!(cin >> s >> t)) return 0;
 
    if (s.length() != t.length()) {
        cout << -1 << "
";
        return 0;
    }
 
    vector<vector<int>> dist(26, vector<int>(26, INF));
    for (int i = 0; i < 26; ++i) {
        dist[i][i] = 0;
    }
 
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        int from = u - 'a';
        int to = v - 'a';
        dist[from][to] = min(dist[from][to], w);
    }
 
    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
 
    long long totalCost = 0;
    string result = "";
    int len = s.length();
 
    for (int i = 0; i < len; ++i) {
        int u = s[i] - 'a';
        int v = t[i] - 'a';
 
        int minCharCost = INF;
        char bestChar = ' ';
 
        for (int c = 0; c < 26; ++c) {
            if (dist[u][c] < INF && dist[v][c] < INF) {
                if (dist[u][c] + dist[v][c] < minCharCost) {
                    minCharCost = dist[u][c] + dist[v][c];
                    bestChar = (char)('a' + c);
                }
            }
        }
 
        if (minCharCost == INF) {
            cout << -1 << "
";
            return 0;
        }
 
        totalCost += minCharCost;
        result += bestChar;
    }
 
    cout << totalCost << "
";
    cout << result << "
";
 
    return 0;
}