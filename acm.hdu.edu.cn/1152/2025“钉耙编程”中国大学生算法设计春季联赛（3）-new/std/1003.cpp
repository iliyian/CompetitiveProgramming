#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
void solve() {
    int n, m; cin >> n >> m;
    vector<ll>a(m + 1);
    vector<vector<int>> c(n + 1, vector<int>(m + 1)), w(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> c[i][j];
        for (int j = 1; j <= m; ++j) cin >> w[i][j];
    }

    vector<int> err(n + 1);
    vector<priority_queue<pii, vector<pii>, greater<pii>>> pq(m + 1);
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (c[i][j] > a[j]) {
                err[i]++;
                pq[j].push({c[i][j], i});
            }
        }
        if (!err[i])q.push(i);
    }

    int cnt = 0;
    while (!q.empty()) {
        ++cnt;
        int u = q.front(); q.pop();
        for (int i = 1; i <= m; ++i) {
            a[i] += w[u][i];
            while (!pq[i].empty() && a[i] >= pq[i].top().first) {
                auto [c, v] = pq[i].top(); pq[i].pop();
                if (--err[v] == 0) q.push(v);
            }
        }
    }

    if (cnt == n) cout << "YES\n";
    else cout << "NO\n";
}
signed main(signed argc, char const* argv[]) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int TxT = 1; cin >> TxT;
    while (TxT--)
        solve();
    return 0;
}
