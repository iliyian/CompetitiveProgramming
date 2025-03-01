#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> ans;
    std::set<int> s;
    int t = 1;
    while (ans.size() < n) {
        auto tmp = ans;
        ans.push_back(t++);
        ans.insert(ans.end(), tmp.begin(), tmp.end());
    }
    std::cout << '\n';
    return 0;
}