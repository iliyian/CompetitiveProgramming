#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
template <const int T>
struct ModInt
{
    const static int mod = T;
    int x;
    ModInt(int x = 0) : x(x % mod) {}
    ModInt(long long x) : x(int(x % mod)) {}
    int val() { return x; }
    ModInt operator+(const ModInt &a) const
    {
        int x0 = x + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }
    ModInt operator-(const ModInt &a) const
    {
        int x0 = x - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }
    ModInt operator*(const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }
    ModInt operator/(const ModInt &a) const { return *this * a.inv(); }
    void operator+=(const ModInt &a)
    {
        x += a.x;
        if (x >= mod)
            x -= mod;
    }
    void operator-=(const ModInt &a)
    {
        x -= a.x;
        if (x < 0)
            x += mod;
    }
    void operator*=(const ModInt &a) { x = 1LL * x * a.x % mod; }
    void operator/=(const ModInt &a) { *this = *this / a; }
    friend ModInt operator+(int y, const ModInt &a)
    {
        int x0 = y + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }
    friend ModInt operator-(int y, const ModInt &a)
    {
        int x0 = y - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }
    friend ModInt operator*(int y, const ModInt &a) { return ModInt(1LL * y * a.x % mod); }
    friend ModInt operator/(int y, const ModInt &a) { return ModInt(y) / a; }
    friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x; }
    friend istream &operator>>(istream &is, ModInt &t) { return is >> t.x; }
    ModInt pow(int64_t n) const
    {
        ModInt res(1), mul(x);
        while (n)
        {
            if (n & 1)
                res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
    ModInt inv() const
    {
        int a = x, b = mod, u = 1, v = 0;
        while (b)
        {
            int t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        if (u < 0)
            u += mod;
        return u;
    }
};
typedef ModInt<P> mint;

template <class info>
struct MATRIX_D
{
    static int N;
    vector<vector<info>> g;
    MATRIX_D(int n) : g(n, vector<info>(n)) {}
    static void set(int x)
    {
        N = x;
    }
    vector<info> &operator[](size_t x) { return g[x]; }
    const vector<info> &operator[](size_t x) const { return g[x]; }
    using M = MATRIX_D<info>;
    using Mc = const M &;
    friend M operator*(Mc a, Mc b)
    {
        const int N = M::N;
        M res(N);
        for (int i = 0; i < N; i++)
        {
            for (int k = 0; k < N; k++)
            {
                auto tmp = a[i][k];
                for (int j = 0; j < N; j++)
                    res[i][j] += b[k][j] * tmp;
            }
        }
        return res;
    }
    friend M &operator*=(M &a, Mc b)
    {
        return a = a * b;
    }
    friend M operator+(Mc a, Mc b)
    {
        const int N = M::N;
        M res(N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                res[i][j] = a[i][j] + b[i][j];
        return res;
    }
    friend M &operator+=(M &a, Mc b)
    {
        const int N = M::N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] += b[i][j];
        return a;
    }
    friend M operator-(Mc a, Mc b)
    {
        const int N = M::N;
        M res(N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                res[i][j] = a[i][j] - b[i][j];
        return res;
    }
    friend M &operator-=(M &a, Mc b)
    {
        const int N = M::N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] -= b[i][j];
        return a;
    }
    void neutralize()
    {
        const int N = M::N;
        for (int i = 0; i < N; i++)
            g[i][i] = 1;
    }
    bool unit()
    {
        const int N = M::N;
        bool f = 1;
        for (int i = 0; i < N && f; i++)
            for (int j = 0; j < N && f; j++)
                if (i == j && g[i][j] != 1 || i != j && g[i][j] != 0)
                    f = 0;
        return f;
    }
    M pow(int64_t x)
    {
        const int N = M::N;
        M res(N), a = (*this);
        res.neutralize();
        while (x)
        {
            if (x & 1)
                res *= a;
            a *= a;
            x >>= 1;
        }
        return res;
    }
};

using mat = MATRIX_D<mint>;

template <class T>
int MATRIX_D<T>::N = 0;

void check(int64_t n, int mod, int t)
{
    vector<mint> f(mod);
    f[0] = 1;
    for (int i = 1; i <= t; i++)
    {
        auto pf = f;
        for (int j = 0; j < mod; j++)
            f[(i + j) % mod] += pf[j];
    }
    // cout << f[0] - 1 << '\n';
    cout << "SEQ: ";
    for (int i = 0; i < mod; i++)
        cout << f[i] << " \n"[i == mod - 1];
}

void solve()
{
    int64_t n;
    int m;
    cin >> n >> m;
    mat::set(m);
    mat res(m);
    res[0][0] = 1;
    mat M(m);
    vector f(m + 1, vector<mint>(m, mint(0)));
    f[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < m; j++)
            f[i][(i + j) % m] = f[i - 1][(i + j) % m] + f[i - 1][j];
    for (int i = 0; i < m; i++)
        M[0][i] = f[m][i];
    for (int i = 1; i < m; i++)
        for (int j = 0; j < m; j++)
            M[i][(j + 1) % m] = M[i - 1][j];

    int col = 0;
    for (int i = 0, rem = (n - 1) % m + 1; i <= rem; i++)
        col += i;
    col %= m;
    mat R(m);
    for (int i = 0; i < m; i++)
        R[col][i] = f[(n - 1) % m + 1][i];
    for (int i = 1; i < m; i++)
        for (int j = 0; j < m; j++)
            R[(col + i) % m][(j + 1) % m] = R[(col + i - 1) % m][j];
    res = res * M.pow((n - 1) / m) * R;
    cout << res[0][0] - 1 << '\n';
}
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    auto t = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
#ifdef LOCAL
    cerr << clock() - t << '\n';
#endif
    return 0;
}
