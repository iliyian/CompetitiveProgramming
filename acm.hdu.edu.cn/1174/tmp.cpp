#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define endl "\n"
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
typedef double db;
const db eps = 1e-8;
#define mkunique(x) \
    sort(all(x));   \
    (x).erase(unique(all(x)), (x).end())
#define inf 2000'000'000'000'000'000
template <typename T>
bool kmax(T &x, const T y)
{
    if (x < y)
        return x = y, 1;
    return 0;
}
template <typename T>
bool kmin(T &x, const T y)
{
    if (y < x)
        return x = y, 1;
    return 0;
}
#define maxn 200003
const int mod = 998244353;
mt19937_64 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
    int n;
    map<int, ull> mp;
    set<ull> ans;
    cin >> n;
    rep(i, 1, n)
    {
        int l, r;
        cin >> l >> r;
        ull val = rng();
        mp[l] ^= val, mp[r + 1] ^= val;
    }
    ull x = 0;
    ans.insert(0);
    for (auto &[a, b] : mp)
        x ^= b, ans.insert(x);
    cout << ans.size() << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}