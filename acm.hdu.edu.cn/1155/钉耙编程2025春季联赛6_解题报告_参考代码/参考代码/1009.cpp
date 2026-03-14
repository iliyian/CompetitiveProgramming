#include<bits/stdc++.h>

using i64 = long long;

const int M = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    const int N = 1e6;
    std::vector<i64> mi(N + 1, 1);
    std::vector<i64> inv(N + 1, 1);
    auto ksm = [&](i64 x, i64 y) {
        i64 ans = 1;
        while (y) {
            if (y & 1) ans = ans * x % M;
            x = x * x % M;
            y >>= 1;
        }
        return ans;
    };
    for (int i = 1; i <= N; i++) {
        mi[i] = mi[i - 1] * 5 % M;
    }
    inv[N] = ksm(mi[N], M - 2);
    for (int i = N - 1; i >= 1; i--) {
        inv[i] = inv[i + 1] * 5 % M;
    }
    while (T--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<i64> dp(n + 1), sum(n + 1);
        i64 ans = 0;
        dp[0] = 1;
        sum[0] = ksm(5, n);
        for (int i = 1; i <= n; i++) {
            int l = i - m - 1;
            if (l > 0) dp[i] = (sum[i - 1] - sum[l - 1] + M) % M;
            else dp[i] = sum[i - 1];
            dp[i] = dp[i] * inv[n - i + 1] % M;
            dp[i] = dp[i] * 21 % M;
            sum[i] = (dp[i] * mi[n - i] + sum[i - 1]) % M;
        }
        for (int i = n; i >= n - m; i--) {
            ans += dp[i] * mi[n - i] % M;
            ans %= M;
        }
        std::cout << ans << "\n";
    }
}