#include<bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<i64> a(n + 1);
        i64 SUM = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            SUM += a[i];
        }
        std::vector ve(n + 1, std::vector<int>());
        for (int i = 1; i < n; i++) {
            int u, v;
            std::cin >> u >> v;
            ve[u].push_back(v);
            ve[v].push_back(u);
        }
        std::vector<int> b(n + 1);
        std::vector<int> cnt(n + 1);
        for (int i = 1; i <= m; i++) {
            int x;
            std::cin >> x;
            b[x] = 1;
            cnt[x] = 1;
        }
        int tar = 0;
        for (int i = 1; i < n; i++) {
            for (auto& j : ve[i]) {
                if (b[i] && b[j]) {
                    if (!tar) std::cout << -1 << "\n";
                    tar = 1;
                }
            }
        }
        if (tar) continue;
        if (m == 1) {
            std::cout << SUM << "\n";
            continue;
        }
        using i128 = __int128;
        std::vector dp(n + 1, std::vector(2, std::vector<i128>(2)));
        auto dfs = [&](auto dfs, int u, int fa) -> void {
            i128 sum = 0;
            for (auto& i : ve[u]) {
                if (i == fa) continue;
                dfs(dfs, i, u);
                sum += std::max(dp[i][0][0], dp[i][1][0]);
            }
            if (b[u]) {
                dp[u][0][0] = -1e18;
                dp[u][0][1] = a[u];
                dp[u][1][0] = -1e18;
            }
            else {
                dp[u][0][0] = a[u];
                dp[u][0][1] = -1e18;
                dp[u][1][0] = 0;
            }
            dp[u][1][1] = -1e18;
            for (auto& i : ve[u]) {
                if (i == fa) continue;
                if (b[u]) {
                    dp[u][0][1] += std::max(dp[i][0][0], dp[i][1][0]);
                }
                else {
                    dp[u][0][0] += std::max(dp[i][0][0], dp[i][1][0]);
                    i128 t = a[u] + sum - std::max(dp[i][0][0], dp[i][1][0]) + dp[i][0][1];
                    dp[u][0][1] = std::max(dp[u][0][1], t);
                    dp[u][1][0] += std::max(dp[i][0][1], dp[i][1][0]);
                }
            }
        };
        dfs(dfs, 1, 0);
        auto ma = std::max({dp[1][0][1], dp[1][1][0]});
        i64 ans = ma;
        std::cout << ans << "\n";
    }
}