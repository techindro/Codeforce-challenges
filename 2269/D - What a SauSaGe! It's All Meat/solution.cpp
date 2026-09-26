#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int INF = 1e9;
 
struct Node {
    int dp[16];
    Node() {
        fill(dp, dp + 16, -INF);
    }
};
 
int n, q;
vector<int> a;
vector<Node> tree;
 
bool in_H(int val) {
    return (val == 0 || val == 3 || val == 5 || val == 6 || val == 9 || val == 10 || val == 12 || val == 15);
}
 
Node combine(const Node& left, const Node& right) {
    Node res;
    for (int i = 0; i < 16; i++) {
        if (left.dp[i] < 0) continue;
        for (int j = 0; j < 16; j++) {
            if (right.dp[j] < 0) continue;
            if (left.dp[i] + right.dp[j] > res.dp[i ^ j]) {
                res.dp[i ^ j] = left.dp[i] + right.dp[j];
            }
        }
    }
    return res;
}
 
void build(int node, int start, int end) {
    if (start == end) {
        for (int v = 0; v < 16; v++) {
            if (in_H(v ^ a[start])) {
                tree[node].dp[v] = (v % 3 == 0) ? 1 : 0;
            } else {
                tree[node].dp[v] = -INF;
            }
        }
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}
 
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        for (int v = 0; v < 16; v++) {
            if (in_H(v ^ val)) {
                tree[node].dp[v] = (v % 3 == 0) ? 1 : 0;
            } else {
                tree[node].dp[v] = -INF;
            }
        }
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) {
        update(2 * node, start, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, end, idx, val);
    }
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}
 
void solve() {
    cin >> n >> q;
    a.resize(n);
    int total_xor = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_xor ^= a[i];
    }
    
    tree.assign(4 * n, Node());
    build(1, 0, n - 1);
    
    cout << max(0, tree[1].dp[total_xor]) << " ";
    
    while (q--) {
        int p, x;
        cin >> p >> x;
        p--;
        total_xor ^= a[p] ^ x;
        a[p] = x;
        update(1, 0, n - 1, p, x);
        cout << max(0, tree[1].dp[total_xor]) << " ";
    }
    cout << "
";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}