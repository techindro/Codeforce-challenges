#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct House {
    double left;
    double right;
};
 
bool compareHouses(const House& h1, const House& h2) {
    return h1.left < h2.left;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    double t;
    if (!(cin >> n >> t)) return 0;
    
    vector<House> houses(n);
    for (int i = 0; i < n; ++i) {
        double x, a;
        cin >> x >> a;
        houses[i].left = x - a / 2.0;
        houses[i].right = x + a / 2.0;
    }
    
    sort(houses.begin(), houses.end(), compareHouses);
    
    int ans = 2; 
    
    for (int i = 0; i < n - 1; ++i) {
        double gap = houses[i+1].left - houses[i].right;
        if (gap > t) {
            ans += 2;
        } else if (abs(gap - t) < 1e-9) {
            ans += 1;
        }
    }
    
    cout << ans << "
";
    
    return 0;
}