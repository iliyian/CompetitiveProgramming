#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct info { int ck; bool sat; };

void solve() {
    int n, m; cin >> n >> m;
    vector<info> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i].ck;
    for (int i = 1; i <= m; ++i) { int p; cin >> p; a[p].sat = 1; }
    sort(a.begin() + 1, a.end(), [&](info x, info y) {return x.ck < y.ck; });
    vector<array<ll, 2>>f(n + 1, {INF, INF});
    f[1][0] = 0;
    if (!a[1].sat) f[2][0] = 0;

    auto pw = [&](int x) { return 1ll * x * x; };

    f[2][1] = pw(a[2].ck - a[1].ck);
    for (int i = 3; i <= n; ++i) {
        f[i][1] = f[i - 1][0] + pw(a[i].ck - a[i - 1].ck);
        if (!a[i - 1].sat) {
            f[i][0] = min(f[i - 1][0], f[i - 1][1]);
            f[i][1] = min(f[i][1], f[i - 2][0] + pw(a[i].ck - a[i - 2].ck));
        } else {
            f[i][0] = f[i - 1][1];
        }
    }
    ll ans = f[n][1];
    if (!a[n].sat)ans = min(ans, f[n][0]);
    cout << ans << '\n';
}
signed main(signed argc, char const* argv[]) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int TxT = 1; cin >> TxT;
    while (TxT--) solve();
    return 0;
}
