#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <chrono>
 
const int MAXA = 1000005;
int spf[MAXA];
uint64_t prime_hash[MAXA];
uint64_t val_hash[MAXA];
 
void precompute() {
    for (int i = 2; i < MAXA; ++i) {
        if (spf[i] == 0) {
            for (int j = i; j < MAXA; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
    std::mt19937_64 rng(13377331);
    for (int i = 2; i < MAXA; ++i) {
        if (spf[i] == i) {
            prime_hash[i] = rng();
        }
    }
    val_hash[1] = 0;
    for (int i = 2; i < MAXA; ++i) {
        int temp = i;
        uint64_t h = 0;
        while (temp > 1) {
            int p = spf[temp];
            int count = 0;
            while (temp % p == 0) {
                count++;
                temp /= p;
            }
            if (count % 2 != 0) {
                h ^= prime_hash[p];
            }
        }
        val_hash[i] = h;
    }
}
 
void solve() {
    int unblended = 0;
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
 
    std::unordered_map<uint64_t, long long> prefix_freq;
    uint64_t current_prefix_hash = 0;
 
    for (int j = 0; j < n; ++j) {
        current_prefix_hash ^= val_hash[a[j]];
        prefix_freq[current_prefix_hash]++;
    }
 
    long long capricious_count = 0;
    for (int i = 0; i < n; ++i) {
        uint64_t req_hash = val_hash[a[i]];
        if (prefix_freq.find(req_hash) != prefix_freq.end()) {
            capricious_count += prefix_freq[req_hash];
        }
    }
 
    std::cout << capricious_count << "
";
}
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    precompute();
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}