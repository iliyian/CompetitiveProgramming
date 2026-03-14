#include<bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n + 1);
        std::vector b(2, std::vector<int>());
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        std::string s;
        std::cin >> s;
        s = " " + s;
        for (int i = 1; i <= n; i++) {
            int t = s[i] == 'R';
            b[t].push_back(a[i]);
        }
        std::sort(b[0].begin(), b[0].end());
        std::sort(b[1].begin(), b[1].end());
        i64 ans = 0;
        while (1) {
            if (!b[1].size()) break;
            ans += b[1].back();
            b[1].pop_back();

            if (!b[0].size()) break;
            ans += b[0].back();
            b[0].pop_back();
        }
        std::cout << ans << "\n";
    }
}