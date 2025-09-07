 #include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
constexpr int N = 1E6;
constexpr int mod = 1E9 + 7;

ll fac[N + 1], facc[N + 1], inv[N + 1];

ll C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * facc[m] % mod * facc[n - m] % mod;
}

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    int c0 = 0, c1 = 0, c2 = 0, c3 = 0;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int s = 0;
        bool ok = true;
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            if (x > 1) {
                ok = false;
            }

            s ^= x;
        }

        cnt += k;


        if (ok) {
            if (s) {
                c1++; // 奇数�?
            }
            else {
                c0++; // 偶数�?
            }
        }
        else {
            if (s) {
                c3++; // 不为0
            }
            else {
                c2++; // �?
            }
        }
    }


    if (c2 + c3 == 0) {
        if (c1 & 1) {
            cout << fac[n] << endl;
        }
        else {
            cout << 0 << endl;
        }

        return;
    }

    ll ans = 0;
    for (int i = 0; i <= c1; i++) {
        if (i & 1) {
            ans += C(c1, i) * fac[i] % mod * c2 % mod * fac[c2 + c3 - 1 + c1 - i] % mod;
            ans %= mod;
        }
        else {
            ans += C(c1, i) * fac[i] % mod * c3 % mod * fac[c2 + c3 - 1 + c1 - i] % mod;
            ans %= mod;
        }
    }

    for (int i = 1; i <= c0; i++) {
        ans = ans * (n - c0 + i) % mod;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = facc[0] = inv[1] = 1;

    const int p = mod;
    for (int i = 2; i <= N; i++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
    }

    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i % mod;
        facc[i] = facc[i - 1] * inv[i] % mod;
    }

    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}