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
        std::vector<int> a(n + 1), b = a;
        std::vector<i64> f(n + 1);
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            f[i] = f[i - 1] + a[i];
        }
        int cnt = 0;
        i64 ans = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> b[i];
            b[i] += a[i];
            if (b[i] == b[i - 1]) cnt++;
            else cnt = 1;
            ans = std::max(ans, cnt * (f[i] - f[i - cnt]));
        }
        std::cout << ans << "\n";
    }
}