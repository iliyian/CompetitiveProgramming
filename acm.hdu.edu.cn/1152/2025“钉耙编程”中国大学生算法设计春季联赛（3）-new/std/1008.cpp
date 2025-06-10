#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1000000007;
int qpow(int a, int b) {
    int res = 1;

    while (b) {
        if (b & 1)
            res = (long long)res * a % MOD;

        a = (long long)a * a % MOD, b >>= 1;
    }

    return res;
}
int getinv(int x) {
    return qpow(x, MOD - 2);
}
constexpr int N = 200005;
struct BIT {
    int n;
    long long c[N];
    BIT(): n(0) {
        memset(c, 0, sizeof(c));
    }
    void init(int _n) {
        for (int i = 1; i <= _n; i++)
            c[i] = 0;

        n = _n;
        return;
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, long long y) {
        for (int i = x; i <= n; i += lowbit(i))
            c[i] += y;

        return;
    }
    long long getsum(int x) {
        long long res = 0;

        for (int i = x; i > 0; i -= lowbit(i))
            res += c[i];

        return res;
    }
} Tl, Tr, Tlr, T;
int n, q;
int a[N];
vector<pair<int, int>>query[N];
int ans[N];
int lst[N];
void solve() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        query[i].clear();

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        query[r].emplace_back(l, i);
    }

    Tl.init(n), Tr.init(n), Tlr.init(n), T.init(n);

    for (int i = 1; i <= n; i++)
        lst[i] = 0;

    for (int r = 1; r <= n; r++) {
        if (lst[a[r]]) {
            Tl.add(1, -r + 1);
            Tl.add(lst[a[r]] + 1, r - 1);
            Tr.add(1, -lst[a[r]] - 1);
            Tr.add(lst[a[r]] + 1, lst[a[r]] + 1);
            Tlr.add(1, 1);
            Tlr.add(lst[a[r]] + 1, -1);
            T.add(1, -(long long)(lst[a[r]] + 1) * (-r + 1));
            T.add(lst[a[r]] + 1, (long long)(lst[a[r]] + 1) * (-r + 1));
        }

        lst[a[r]] = r;

        for (auto [l, id] : query[r]) {
            int len = r - l + 1;
            ans[id] = ((long long)len * (len + 1) * (len + 2) / 6 + (long long)Tl.getsum(l) % MOD * l +
                       (long long)Tr.getsum(l) % MOD * r + (long long)Tlr.getsum(l) % MOD * l % MOD * r + T.getsum(l)) % MOD;
            ans[id] = (long long)ans[id] % MOD * getinv((long long)len * (len + 1) / 2 % MOD) % MOD;
        }
    }

    for (int i = 1; i <= q; i++)
        cout << ans[i] << "\n";

    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}