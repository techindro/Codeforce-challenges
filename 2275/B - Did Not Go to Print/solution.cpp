#include <iostream>
#include <vector>
#include <string>
#include <stack>
 
void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
 
    std::stack<int> memory;
    std::vector<bool> printed(n + 1, false);
 
    for (int i = 0; i < n; ++i) {
        int doc_id = i + 1;
        if (s[i] == '1') {
            memory.push(doc_id);
        } else if (s[i] == '2') {
            if (!memory.empty()) {
                printed[memory.top()] = true;
                memory.pop();
            } else {
                printed[doc_id] = true;
            }
        } else if (s[i] == '3') {
            printed[doc_id] = true;
        }
    }
 
    std::vector<int> not_printed;
    for (int i = 1; i <= n; ++i) {
        if (!printed[i]) {
            not_printed.push_back(i);
        }
    }
 
    std::cout << not_printed.size() << "
";
    for (size_t i = 0; i < not_printed.size(); ++i) {
        std::cout << not_printed[i] << (i + 1 == not_printed.size() ? "" : " ");
    }
    std::cout << "
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