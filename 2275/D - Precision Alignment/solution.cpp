#include <iostream>
#include <vector>
#include <algorithm>
 
struct Lab {
    long long a, b, c;
};
 
bool check(long long target, const std::vector<Lab>& labs, long long k) {
    long long total_ops = 0;
    for (const auto& lab : labs) {
        long long current_sum = lab.a + lab.b + lab.c;
        if (current_sum >= target) continue;
 
        if (lab.a == lab.b && lab.b == lab.c) {
            if (target > current_sum) return false;
            continue;
        }
 
        long long required = target - current_sum;
        long long extra_ops = 0;
 
        if (lab.a <= lab.b && lab.b <= lab.c) {
            extra_ops = 2 * (lab.b - lab.a + 1);
            if (lab.a < lab.b) {
                extra_ops = std::min(extra_ops, 2 * (lab.c - lab.b + 1));
            }
        }
 
        total_ops += (required + extra_ops);
        if (total_ops > k || total_ops < 0) return false;
    }
    return total_ops <= k;
}
 
void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<Lab> labs(n);
    long long min_sum = 4e18;
    for (int i = 0; i < n; ++i) {
        std::cin >> labs[i].a >> labs[i].b >> labs[i].c;
        min_sum = std::min(min_sum, labs[i].a + labs[i].b + labs[i].c);
    }
 
    long long low = min_sum;
    long long high = min_sum + k;
    long long ans = low;
 
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, labs, k)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    std::cout << ans << "
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