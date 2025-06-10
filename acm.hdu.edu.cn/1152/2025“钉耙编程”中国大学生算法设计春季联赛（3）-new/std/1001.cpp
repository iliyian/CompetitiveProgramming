#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, mod = 998244353;
int a[N], L[N], fac[40], pre[40];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        cin >> L[i];
        L[i] = min(L[i], a[i]);
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        pre[0] = 1 << (a[i] & 1);
        for (int k = 1; k <= 30; ++k)
            pre[k] = (pre[k - 1] << ((a[i] >> k) & 1)) % mod;
        for (int k = 30; k >= 0; --k) {
            if ((L[i] >> k) & 1) {
                if ((a[i] >> k) & 1) {
                    if (k == 0) cnt = (cnt + pre[0]) % mod;
                    else cnt = (cnt + pre[k - 1]) % mod;
                } else {
                    cnt = (cnt + pre[k]) % mod;
                    break;
                }
            } else if (k == 0) cnt = (cnt + 1) % mod;
        }
        ans = 1ll * ans * cnt % mod;
    }
    cout << ans << endl;
}
int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    cout.tie(0);
    fac[0] = 1;
    for (int i = 1; i <= 30; ++i)
        fac[i] = fac[i] * 2 % mod;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
/*
1
4
3
2
4
*/