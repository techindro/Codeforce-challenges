#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    vector<long long> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums.begin(), nums.end());
    
    while (nums[2] > nums[0] + nums[1]) {
        nums[2] = nums[0] + nums[1];
        sort(nums.begin(), nums.end());
    }
    
    cout << nums[2] - nums[0] << "
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