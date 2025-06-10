#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mod = 998244353;
int inv[N], sum[N], fac[N], ifac[N];
bool visR[N], visC[N];
int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod, b >>= 1;
    }
    return res;
}
int C(int n, int m) {
    return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
void solve() {
    int n, m, k, x, y;
    cin >> n >> m >> k;
    int nm = n * m;
    int ans = 0;
    while (k--) {
        cin >> x >> y;
        visR[x] = 1;
        visC[y] = 1;
    }
    int totR = n, totC = m;
    for (int i = 1; i <= n; ++i)
        if (visR[i]) totR--, visR[i] = 0;
    for (int i = 1; i <= m; ++i)
        if (visC[i]) totC--, visC[i] = 0;
    if (totR + totC == 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i <= totR; ++i)
        for (int j = 0; j <= totC; ++j) {
            int f = 1, tot = i * m + j * n - i * j;
            if ((i + j + 1) & 1) f = mod - 1;
            ans = (ans + 1ll * f * C(totR, i) % mod * C(totC, j) % mod * sum[tot] % mod * nm) % mod;
        }
    cout << ans << endl;
}
int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    cout.tie(0);
    int n = 1e6;
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    for (int i = 1; i <= n; ++i)
        sum[i] = (sum[i - 1] + inv[i]) % mod;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[n] = power(fac[n], mod - 2);
    for (int i = n; i >= 1; --i)
        ifac[i - 1] = 1ll * ifac[i] * i % mod;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}