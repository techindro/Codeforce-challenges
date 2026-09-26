#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
long long get_next(long long x) {
    long long sum = 0;
    while (x > 0) {
        long long digit = x % 10;
        sum += digit * digit;
        x /= 10;
    }
    return sum;
}
 
void solve() {
    int n;
    cin >> n;
    
    map<long long, long long> counts;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        
        for (int step = 0; step < 100; step++) {
            a = get_next(a);
        }
        counts[a]++;
    }
    
    long long ans = 0;
    for (auto const& [val, count] : counts) {
        ans += (count * (count - 1)) / 2;
    }
    
    cout << ans << "
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