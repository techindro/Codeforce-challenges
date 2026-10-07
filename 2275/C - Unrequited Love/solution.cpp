#include <iostream>
#include <vector>
#include <map>
 
void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
 
    int m = n - 4;
    std::vector<long long> v(m);
    std::map<long long, long long> freq;
    long long total_pairs = 0;
 
    for (int i = 0; i < m; ++i) {
        v[i] = a[i] + a[i + 2] - a[i + 4];
        total_pairs += freq[v[i]];
        freq[v[i]]++;
    }
 
    long long overlapping_pairs = 0;
    for (int i = 0; i < m; ++i) {
        if (i + 2 < m && v[i] == v[i + 2]) {
            overlapping_pairs++;
        }
        if (i + 4 < m && v[i] == v[i + 4]) {
            overlapping_pairs++;
        }
    }
 
    std::cout << total_pairs - overlapping_pairs << "
";
}
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}