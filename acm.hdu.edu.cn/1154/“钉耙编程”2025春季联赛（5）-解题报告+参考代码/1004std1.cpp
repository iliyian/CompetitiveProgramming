#include <bits/stdc++.h>
using ll = long long;

typedef std::vector<int> poly;
const int mod = 998244353;
const int N = 4000000 + 5;

int rf[32][N];
int fpow(int a, int b)
{
    int res = 1;
    for (; b; b >>= 1, a = a * 1ll * a % mod)
        if (b & 1)
            res = res * 1ll * a % mod;
    return res;
}
void init(int n)
{
    assert(n < N);
    int lg = std::__lg(n);
    static std::vector<bool> bt(32, 0);
    if (bt[lg] == 1)
        return;
    bt[lg] = 1;
    for (int i = 0; i < n; i++)
        rf[lg][i] = (rf[lg][i >> 1] >> 1) + ((i & 1) ? (n >> 1) : 0);
}
void ntt(poly &x, int lim, int op)
{
    int lg = std::__lg(lim), gn, g, tmp;
    ;
    for (int i = 0; i < lim; i++)
        if (i < rf[lg][i])
            std::swap(x[i], x[rf[lg][i]]);
    for (int len = 2; len <= lim; len <<= 1)
    {
        int k = (len >> 1);
        gn = fpow(3, (mod - 1) / len);
        for (int i = 0; i < lim; i += len)
        {
            g = 1;
            for (int j = 0; j < k; j++, g = gn * 1ll * g % mod)
            {
                tmp = x[i + j + k] * 1ll * g % mod;
                x[i + j + k] = (x[i + j] - tmp + mod) % mod;
                x[i + j] = (x[i + j] + tmp) % mod;
            }
        }
    }
    if (op == -1)
    {
        reverse(x.begin() + 1, x.begin() + lim);
        int inv = fpow(lim, mod - 2);
        for (int i = 0; i < lim; i++)
            x[i] = x[i] * 1ll * inv % mod;
    }
}
poly multiply(const poly &a, const poly &b)
{
    assert(!a.empty() && !b.empty());
    int lim = 1;
    while (lim + 1 < int(a.size() + b.size()))
        lim <<= 1;
    init(lim);
    poly pa = a, pb = b;
    while (pa.size() < lim)
        pa.push_back(0);
    while (pb.size() < lim)
        pb.push_back(0);
    ntt(pa, lim, 1);
    ntt(pb, lim, 1);
    for (int i = 0; i < lim; i++)
        pa[i] = pa[i] * 1ll * pb[i] % mod;
    ntt(pa, lim, -1);
    while (int(pa.size()) + 1 > int(a.size() + b.size()))
        pa.pop_back();
    for (int i = a.size(); i < pa.size(); i++)
    {
        pa[i % a.size()] += pa[i];
        pa[i % a.size()] %= mod;
    }
    pa.resize(a.size());
    return pa;
}

void add(int &x, int y)
{
    ((x += y) >= mod) && (x -= mod);
}

poly fpow(poly a, ll b)
{
    poly res(a.size(), 0);
    res[0] = 1;
    for (; b; b >>= 1, a = multiply(a, a))
        if (b & 1)
            res = multiply(res, a);
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--)
    {
        ll n;
        int m;
        std::cin >> n >> m;
        poly dp(m, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++)
        {
            poly x(m, 0);
            x[i] = 1;
            ++x[0];
            dp = multiply(dp, x);
        }
        dp = fpow(dp, (n / m) % (mod - 1));
        int rem = n % m;
        for (int i = 1; i <= rem; i++)
        {
            poly x(m, 0);
            x[i] = 1;
            x[0] = 1;
            dp = multiply(dp, x);
        }
        std::cout << (dp[0] + mod - 1) % mod << '\n';
    }
    return 0;
}