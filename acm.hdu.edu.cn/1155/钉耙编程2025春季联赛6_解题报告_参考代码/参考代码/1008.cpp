#include<bits/stdc++.h>

const int M = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int ans = 1, sum = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            std::cin >> x;
            sum = (sum + 1ll * x * y) % M;
            int t = (1ll * i * (i - 1) / 2) % M;
            if (i > 1) ans = 1ll * ans * t % M;
            y = (y + x) % M;
        }
        std::cout << sum << " " << ans << "\n";
    }
}