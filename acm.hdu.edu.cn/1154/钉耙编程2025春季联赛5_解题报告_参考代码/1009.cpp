#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
int fastpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1) ans = 1ll * ans * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return ans;
}

int inv(int x)
{
    return fastpow(x, mod - 2);
}

void solve()
{

    int n; cin >> n;
    if (n % 5 == 0 or n % 5 == 2)
    {
        cout << 1 << "\n";
        return;
    }

    int a[] = {0, inv(2), inv(2), 3 * inv(4) % mod, inv(2)};
    if (n <= 4)
    {
        cout << a[n] << "\n";
        return;
    }

    a[0] = (1 - inv(fastpow(2, n / 5 - 1)) + mod) % mod;
    a[2] = (a[0] + 1) * inv(2) % mod;
    a[1] = (inv(4) * a[0] % mod + inv(2) * a[2] % mod + inv(4)) % mod;
    
    a[0] = (a[0] + 1) * inv(2) % mod;
    a[2] = (a[2] + 1) * inv(2) % mod;
    a[3] = (a[2] + 1) * inv(2) % mod;
    a[4] = (a[0] + 1) * inv(2) % mod;

    cout << a[n % 5] << "\n";

}

signed main()
{

    // freopen("../9.in", "r", stdin);
    // freopen("../9.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1; cin >> T;
    while (T --) solve();
    return 0;
}
/*
6
0 2 5 7 10 12
0
499122177
499122177
249561089
249561089
124780545
*/

/*
4
1
2
8
103

499122177
1
124780545
239
*/