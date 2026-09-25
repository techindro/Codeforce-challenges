#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
 
using namespace std;
 
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
 
void solve() {
    int n;
    long long x;
    cin >> n >> x;
 
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    vector<long long> divs;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            divs.push_back(i);
            if (i * i != x) {
                divs.push_back(x / i);
            }
        }
    }
    sort(divs.rbegin(), divs.rend());
 
    vector<long long> valid_g;
    for (int i = 0; i < n; ++i) {
        valid_g.push_back(gcd(a[i], x));
    }
    sort(valid_g.begin(), valid_g.end());
    valid_g.erase(unique(valid_g.begin(), valid_g.end()), valid_g.end());
 
    vector<bool> reachable(x + 1, false);
    reachable[x] = true;
 
    for (long long d : divs) {
        if (!reachable[d]) continue;
        for (long long g : valid_g) {
            long long new_d = gcd(g, d);
            if (new_d > 1) {
                reachable[new_d] = true;
            }
        }
    }
 
    long long max_coins = 0;
    for (long long d : divs) {
        if (d > 1 && reachable[d]) {
            long long current_sum = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] % d == 0) {
                    current_sum += a[i];
                }
            }
            max_coins = max(max_coins, current_sum);
        }
    }
 
    cout << max_coins << "
";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}