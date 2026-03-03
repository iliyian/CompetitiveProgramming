#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define F(i, x, n) for (int i = x; i <= n; ++i)
#define _F(i, x, n) for (int i = x; i >= n; --i)
#define ll long long
#define ull unsigned long long
#define lson x << 1
#define rson x << 1 | 1
#define lowbit(x) x & -x
#define en puts("")
#define pb push_back
#define int long long
using namespace std;

inline int read()
{
    int s = 0;
    char c = getchar();
    bool flag = 0;
    while (!isdigit(c))
        flag |= (c == '-'), c = getchar();
    while (isdigit(c))
        s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
    return flag ? -s : s;
}

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int qpow(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

int fac[N], inv[N];

int C(int n, int m)
{
    if (n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 1e5; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = qpow(fac[i], mod - 2);
    }
    int x, k;
    cin >> x >> k;
    int ans = 0;
    for (int i = 1; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            int t = x / i - 1;
            // if (t < i)
            //     break;
            // cerr << t << ":\n";
            vector<pair<int, int>> p;
            int num = t;
            for (int j = 2; j * j <= num; ++j)
            {
                if (num % j == 0)
                {
                    int tot = 0;
                    while (num % j == 0)
                        num /= j, ++tot;
                    p.push_back({j, tot});
                }
            }
            if (num > 1)
                p.push_back({num, 1});
            int m = p.size(), res = 0;
            for (int s = 0; s < (1ll << (2 * m)); ++s)
            {
                vector<int> l(m + 5), r(m + 5);
                int cnt = 0;
                for (int j = 0; j < 2 * m; j += 2)
                {
                    if ((1ll << j) & s)
                    {
                        l[j / 2] = 1;
                        cnt++;
                    }
                    else
                        l[j / 2] = 0;
                    if ((1ll << (j + 1)) & s)
                    {
                        r[j / 2] = p[j / 2].second - 1;
                        cnt++;
                    }
                    else
                        r[j / 2] = p[j / 2].second;
                }
                int tot = 1;
                // cerr << s << "---:\n";
                for (int j = 0; j < m; ++j)
                {
                    // cerr << l[j] << " " << r[j] << "\n";
                    if (r[j] < l[j])
                        tot = 0;
                    tot = tot * (r[j] - l[j] + 1);
                }
                // cerr << cnt << " " << tot << "\n";
                if (cnt & 1)
                    res = (res - C(tot, k) + mod) % mod;
                else
                    res = (res + C(tot, k)) % mod;
            }
            // cerr << res << "\n";
            ans = (ans + res) % mod;
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}