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
const int mod = 998244353;

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

struct node
{
    int mn, mx;
} t[N << 2];

int a[N];
int n, q;

void pushup(int x)
{
    t[x] = {min(t[lson].mn, t[rson].mn), max(t[lson].mx, t[rson].mx)};
}

void build(int x, int l, int r)
{
    if (l == r)
    {
        t[x] = {a[l], a[l]};
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid), build(rson, mid + 1, r);
    pushup(x);
}

void upd(int x, int l, int r, int k, int v)
{
    if (l == r)
    {
        t[x].mn += v, t[x].mx += v;
        return;
    }
    int mid = l + r >> 1;
    if (k <= mid)
        upd(lson, l, mid, k, v);
    else
        upd(rson, mid + 1, r, k, v);
    pushup(x);
}

int qry(int x, int l, int r, int L, int R, int op)
{
    if (l > R || r < L)
    {
        if (!op)
            return 1e18;
        else
            return -1e18;
    }
    if (L <= l && r <= R)
    {
        if (!op)
            return t[x].mn;
        else
            return t[x].mx;
    }
    int mid = l + r >> 1;
    if (!op)
        return min(qry(lson, l, mid, L, R, op), qry(rson, mid + 1, r, L, R, op));
    else
        return max(qry(lson, l, mid, L, R, op), qry(rson, mid + 1, r, L, R, op));
}

int Find_l(int l, int r, int x, int op)
{
    int p = r;
    if (!op)
    {
        int res = -1;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (qry(1, 1, n, mid, p, 0) >= x)
                res = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return res;
    }
    else
    {
        int res = -1;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (qry(1, 1, n, mid, p, 1) <= x)
                res = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return res;
    }
}

int Find_r(int l, int r, int x, int op)
{
    int p = l;
    if (!op)
    {
        int res = -1;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (qry(1, 1, n, p, mid, 0) >= x)
                res = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        return res;
    }
    else
    {
        int res = -1;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (qry(1, 1, n, p, mid, 1) <= x)
                res = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        return res;
    }
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        // cerr << i << ":\n";
        int k1 = Find_l(1, i, a[i], 0), k2 = Find_r(i + 1, n, a[i] + 1, 0);
        if (k1 == -1)
            k1 = i;
        if (k2 == -1)
            k2 = i;
        ans -= (i - k1 + 1) * (k2 - i + 1) * a[i];
        // cerr << k1 << " " << k2 << "\n";
        k1 = Find_l(1, i, a[i], 1), k2 = Find_r(i + 1, n, a[i] - 1, 1);
        if (k1 == -1)
            k1 = i;
        if (k2 == -1)
            k2 = i;
        ans += (i - k1 + 1) * (k2 - i + 1) * a[i];
        // cerr << k1 << " " << k2 << "\n";
        // cerr << ans << "\n";
    }
    // cerr << ans << "\n";
    while (q--)
    {
        char op;
        cin >> op;
        int x;
        cin >> x;
        // cerr << op << " " << x << "\n";
        if (op == '-')
        {
            int t = qry(1, 1, n, x, x, 0);
            int k1 = Find_l(1, x - 1, t, 0), k2 = Find_r(x + 1, n, t, 0);
            if (k1 == -1)
                k1 = x;
            if (k2 == -1)
                k2 = x;
            ans += (x - k1 + 1) * (k2 - x + 1);
            // cerr << k1 << " " << k2 << "\n";
            k1 = Find_l(1, x - 1, t - 1, 1), k2 = Find_r(x + 1, n, t - 1, 1);
            if (k1 == -1)
                k1 = x;
            if (k2 == -1)
                k2 = x;
            ans -= (x - k1 + 1) * (k2 - x + 1);
            // cerr << k1 << " " << k2 << "\n";
            upd(1, 1, n, x, -1);
        }
        else
        {
            int t = qry(1, 1, n, x, x, 1);
            int k1 = Find_l(1, x - 1, t + 1, 0), k2 = Find_r(x + 1, n, t + 1, 0);
            if (k1 == -1)
                k1 = x;
            if (k2 == -1)
                k2 = x;
            ans -= (x - k1 + 1) * (k2 - x + 1);
            k1 = Find_l(1, x - 1, t, 1), k2 = Find_r(x + 1, n, t, 1);
            if (k1 == -1)
                k1 = x;
            if (k2 == -1)
                k2 = x;
            ans += (x - k1 + 1) * (k2 - x + 1);
            upd(1, 1, n, x, 1);
        }
        cout << ans << "\n";
    }
}

signed main()
{
    freopen("d.in", "r", stdin);
    freopen("d.out", "r", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}