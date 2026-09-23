#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    long long n, k, m;
    cin >> n >> k >> m;
 
    if (k > m) {
        cout << "NO
";
        return;
    }
 
    cout << "YES
";
    vector<long long> S(n + 1);
    for (int i = 0; i <= n; ++i) {
        S[i] = i % k;
    }
 
    for (int i = 1; i <= n; ++i) {
        long long diff = S[i] - S[i - 1];
        if (diff <= 0) {
            diff += m;
        }
        cout << diff << (i == n ? "" : " ");
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