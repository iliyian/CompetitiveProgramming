/*
          _____                    _____                    _____                    _____                    _____                    _____
         /\    \                  /\    \                  /\    \                  /\    \                  /\    \                  /\    \
        /::\    \                /::\____\                /::\    \                /::\    \                /::\    \                /::\____\
       /::::\    \              /:::/    /               /::::\    \              /::::\    \              /::::\    \              /:::/    /
      /::::::\    \            /:::/    /               /::::::\    \            /::::::\    \            /::::::\    \            /:::/    /
     /:::/\:::\    \          /:::/    /               /:::/\:::\    \          /:::/\:::\    \          /:::/\:::\    \          /:::/    /
    /:::/__\:::\    \        /:::/    /               /:::/__\:::\    \        /:::/__\:::\    \        /:::/__\:::\    \        /:::/____/
   /::::\   \:::\    \      /:::/    /               /::::\   \:::\    \      /::::\   \:::\    \      /::::\   \:::\    \      /::::\    \
  /::::::\   \:::\    \    /:::/    /      _____    /::::::\   \:::\    \    /::::::\   \:::\    \    /::::::\   \:::\    \    /::::::\    \   _____
 /:::/\:::\   \:::\    \  /:::/____/      /\    \  /:::/\:::\   \:::\    \  /:::/\:::\   \:::\    \  /:::/\:::\   \:::\    \  /:::/\:::\    \ /\    \
/:::/  \:::\   \:::\____\|:::|    /      /::\____\/:::/  \:::\   \:::\____\/:::/  \:::\   \:::\____\/:::/  \:::\   \:::\____\/:::/  \:::\    /::\____\
\::/    \:::\   \::/    /|:::|____\     /:::/    /\::/    \:::\   \::/    /\::/    \:::\   \::/    /\::/    \:::\   \::/    /\::/    \:::\  /:::/    /
 \/____/ \:::\   \/____/  \:::\    \   /:::/    /  \/____/ \:::\   \/____/  \/____/ \:::\   \/____/  \/____/ \:::\   \/____/  \/____/ \:::/:::/    /
          \:::\    \       \:::\    \ /:::/    /            \:::\    \               \:::\    \               \:::\    \               \::::::/    /
           \:::\____\       \:::\    /:::/    /              \:::\____\               \:::\____\               \:::\____\               \::::/    /
            \::/    /        \:::\__/:::/    /                \::/    /                \::/    /                \::/    /               /:::/    /
             \/____/          \::::::::/    /                  \/____/                  \/____/                  \/____/               /:::/    /
                               \::::::/    /                                                                                          /:::/    /
                                \::::/    /                                                                                          /:::/    /
                                 \::/____/                                                                                           \::/    /
                                  ~~                                                                                                  \/____/
*/
#include <bits/stdc++.h>
#define int long long
#define ME0(X) memset(X, 0, sizeof(X))
#define debug(x) std::cout << "debug_" << __LINE__ << (x) << '\n'
#define pii pair<int, int>
#define mii map<int, int>
#define umap unordered_map
#define uset unordered_set
#define pb push_back
#define pqueue priority_queue
using namespace std;
using u128 = unsigned __int128;
using i128 = __int128;
using u64 = unsigned long long;
using u32 = unsigned int;
const int MOD = 1e9 + 7, MAXN = 2e5 + 7, INF = 1e18 + 7;
mt19937 mt;
int qpow(int a, int b)
{
    int res = 1;
    for (; b; b >>= 1, a = a * a % MOD)
        if (b & 1)
            res = res * a % MOD;
    return res;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int exgcd(int a, int b, int &x, int &y) { return !b ? (x = 1, y = 0, a) : (exgcd(b, a % b, y, x), y -= a / b * x, a); }
int n;
int a[107][107];
bool flag = true;

int pan(int a, int b, int c)
{
    int t = 0;
    if (a == 100)
        t++;
    if (b == 100)
        t++;
    if (c == 100)
        t++;
    return t;
}

void solve()
{
    cin >> n;
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 100)
                t++;
        }
    }
    int sum = n * (n + 1) / 2;
    while (1)
    {
        bool flag = true;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                int k = a[i][j], b = a[i + 1][j], c = a[i + 1][j + 1];
                if (pan(k, b, c) == 1)
                {
                    if (k == 100)
                        a[i][j] = b + c;
                    if (b == 100)
                        a[i + 1][j] = k - c;
                    if (c == 100)
                        a[i + 1][j + 1] = k - b;
                    t++;
                    flag = false;
                }
                else if (pan(k, b, c) == 0 && k != b + c)
                {
                    cout << "no solution\n";
                    return;
                }
                k = a[i][j], b = a[i + 1][j], c = a[i + 1][j + 1];
                if (k != 100 && (k < -99 || k > 99)) {
                    cout << "no solution\n";
                    return;
                }
                if (b != 100 && (b < -99 || b > 99)) {
                    cout << "no solution\n";
                    return;
                }
                if (c != 100 && (c < -99 || c > 99)) {
                    cout << "no solution\n";
                    return;
                }
            }
        }
        if (t == sum)
        {
            cout << "solvable\n";
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    cout << a[i][j] << " ";
                }
                cout << '\n';
            }
            return;
        }
        if (flag)
        {
            cout << "ambiguous\n";
            return;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}