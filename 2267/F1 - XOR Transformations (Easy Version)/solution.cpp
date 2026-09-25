#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    long long max_val = 0, min_val = 2e18;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
        min_val = min(min_val, a[i]);
    }
 
    vector<long long> history;
    history.push_back(max_val - min_val);
 
    for (int step = 1; step <= 40; ++step) {
        if (max_val == min_val) {
            break; 
        }
 
        vector<long long> xors;
        xors.reserve(n * (n - 1) / 2);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                xors.push_back(a[i] ^ a[j]);
            }
        }
 
        nth_element(xors.begin(), xors.begin() + n, xors.end());
        xors.resize(n);
        sort(xors.begin(), xors.end());
 
        a = xors;
        max_val = a.back();
        min_val = a.front();
        history.push_back(max_val - min_val);
    }
 
    for (int i = 0; i < q; ++i) {
        long long x;
        cin >> x;
        if (x < history.size()) {
            cout << history[x] << "
";
        } else {
            cout << 0 << "
";
        }
    }
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