#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 998244353;

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (long long)res * a % MOD;
        a = (long long)a * a % MOD, b >>= 1;
    }
    return res;
}
int getinv(int x) { return qpow(x, MOD - 2); }

const int N = 1000005;
int fac[N], ifac[N];
int inv[N];
void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = (long long)fac[i - 1] * i % MOD;
    ifac[n] = getinv(fac[n]);
    for (int i = n; i >= 1; i--) ifac[i - 1] = (long long)ifac[i] * i % MOD;
    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = (long long)(MOD - MOD / i) * inv[MOD % i] % MOD;
    return;
}
int C(int n, int m) {
    if (m > n)
        return 0;
    else if (m == 0 || m == n)
        return 1;
    else
        return (long long)fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}
void solve() {
    int m, n;
    cin >> m >> n;
    assert(m >= n);
    int ans = (long long)C(m, n) * C(m - 1, n) % MOD * getinv(n + 1) % MOD;
    cout << ans << "\n";
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init(1000000 + 1);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
