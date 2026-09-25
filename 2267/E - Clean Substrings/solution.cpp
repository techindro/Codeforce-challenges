#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
struct Node {
    int cnt;
    long long val;
    long long sum_alt;
    long long sum_ans;
};
 
int n, q;
string s;
vector<Node> tree;
 
Node merge(const Node& left, const Node& right) {
    Node parent;
    parent.cnt = left.cnt + right.cnt;
    parent.val = right.val + (right.cnt % 2 == 0 ? left.val : -left.val);
    parent.sum_alt = left.sum_alt + (left.cnt % 2 == 0 ? right.sum_alt : -right.sum_alt);
    parent.sum_ans = left.sum_ans + right.sum_ans + left.val * right.sum_alt;
    return parent;
}
 
void update(int node, int start, int end, int idx, bool active) {
    if (start == end) {
        if (active) {
            tree[node].cnt = 1;
            tree[node].val = start;
            tree[node].sum_ans = 1LL * start * (n - start);
            tree[node].sum_alt = -(n - start);
        } else {
            tree[node].cnt = 0;
            tree[node].val = 0;
            tree[node].sum_ans = 0;
            tree[node].sum_alt = 0;
        }
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) {
        update(2 * node, start, mid, idx, active);
    } else {
        update(2 * node + 1, mid + 1, end, idx, active);
    }
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}
 
void solve() {
    cin >> n >> q >> s;
    s = " " + s;
    
    if (n == 1) {
        cout << 0;
        for (int i = 0; i < q; ++i) {
            int idx;
            cin >> idx;
            cout << " " << 0;
        }
        cout << "
";
        return;
    }
 
    tree.assign(4 * n, {0, 0, 0, 0});
 
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i + 1]) {
            update(1, 1, n - 1, i, true);
        }
    }
 
    cout << tree[1].sum_ans;
 
    for (int k = 0; k < q; ++k) {
        int idx;
        cin >> idx;
        s[idx] = (s[idx] == '0' ? '1' : '0');
 
        if (idx > 1) {
            update(1, 1, n - 1, idx - 1, s[idx - 1] != s[idx]);
        }
        if (idx < n) {
            update(1, 1, n - 1, idx, s[idx] != s[idx + 1]);
        }
 
        cout << " " << tree[1].sum_ans;
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