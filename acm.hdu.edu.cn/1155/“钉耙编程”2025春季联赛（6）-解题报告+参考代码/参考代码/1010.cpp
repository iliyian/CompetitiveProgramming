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
        std::vector ve(n + 1, std::vector<int>());
        for (int i = 1; i < n; i++) {
            int u, v;
            std::cin >> u >> v;
            ve[u].push_back(v);
            ve[v].push_back(u);
        }
        std::vector<int> dp(n + 1, 1);
        std::vector<i64> ans(n + 1);
        auto dfs = [&](auto & dfs, int u, int fa) -> void {
            std::vector<int> v;
            i64 sum = 1;
            for (auto& i : ve[u]) {
                if (i == fa) continue;
                dfs(dfs, i, u);
                sum += 1ll * dp[i] * dp[u];
                dp[u] += dp[i];
                v.push_back(dp[i]);
            }
            int t = n - dp[u];
            sum += 1ll * t * dp[u];
            v.push_back(t);
            ans[u] += sum;
            for (auto& i : v) {
                i64 t = sum;
                t -= 1ll * i * (n - i);
                ans[u] += 1ll * i * t;
            }
        };
        dfs(dfs, 1, 0);
        for (int i = 1; i <= n; i++) {
            std::cout << ans[i] << " ";
        }
        std::cout << "\n";
    }
}