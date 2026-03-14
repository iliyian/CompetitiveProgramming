#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100005;
int n;
int s, t;
vector<tuple<int, int, int>> G[N];
long long dp[N];
void dfs(int u, int father) {
    dp[u] = 0;
    for (auto [v, p, q] : G[u]) {
        if (v == father) continue;
        dfs(v, u);
        dp[u] += max(0ll, dp[v] + p + q);
    }
    return;
}
pair<bool, long long> solve(int u, int father) {
    if (u == t) {
        return make_pair(true, dp[u]);
    }
    long long res = 0;
    bool flag = false;
    for (auto [v, p, q] : G[u]) {
        if (v == father) continue;
        auto [ff, val] = solve(v, u);
        if (ff)
            flag = true, res += p + val;
        else
            res += max(0ll, dp[v] + p + q);
    }
    return make_pair(flag, res);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        G[u].emplace_back(v, p, q);
        G[v].emplace_back(u, q, p);
    }
    cin >> s >> t;
    dfs(s, 0);
    auto [flag, ans] = solve(s, 0);
    cout << ans << "\n";
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
