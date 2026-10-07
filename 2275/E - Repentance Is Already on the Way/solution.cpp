#include <iostream>
#include <vector>
#include <algorithm>
 
void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
 
    auto cost = [&](long long company1, long long company2) -> long long {
        return (company1 == company2) ? 2 : 1;
    };
 
    if (n == 1) {
        long long thegrilla = cost(a[0], b[0]);
        std::cout << thegrilla << "
";
        return;
    }
 
    std::vector<long long> suffix_a(n, 0), suffix_b(n, 0);
    suffix_a[n - 1] = cost(a[n - 1], b[n - 1]);
    suffix_b[n - 1] = cost(b[n - 1], a[n - 1]);
 
    for (int i = n - 2; i >= 0; --i) {
        suffix_a[i] = cost(a[i], b[i + 1]) + suffix_b[i + 1] + cost(a[i + 1], b[i]);
        suffix_b[i] = cost(b[i], a[i + 1]) + suffix_a[i + 1] + cost(b[i + 1], a[i]);
    }
 
    std::vector<long long> dp(n, 0);
    dp[0] = cost(a[0], b[0]);
 
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1] + cost(b[i - 1], a[i]) + cost(a[i], b[i]);
    }
 
    long long thegrilla = suffix_a[0];
 
    for (int i = 1; i < n; ++i) {
        long long current_option = dp[i - 1] + cost(b[i - 1], a[i]) + suffix_a[i];
        thegrilla = std::max(thegrilla, current_option);
    }
 
    thegrilla = std::max(thegrilla, dp[n - 1]);
 
    std::cout << thegrilla << "
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