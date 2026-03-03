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
 \/____/ \:::\   \/____/  \:::\    \   /:::/    /  \/____/ \:::\   \/____/  \/____/ \:::\   \/____/  \/____/ \:::\   \/____/  \/____/ \:::\/:::/    /
          \:::\    \       \:::\    \ /:::/    /            \:::\    \               \:::\    \               \:::\    \               \::::::/    /
           \:::\____\       \:::\    /:::/    /              \:::\____\               \:::\____\               \:::\____\               \::::/    /
            \::/    /        \:::\__/:::/    /                \::/    /                \::/    /                \::/    /               /:::/    /
             \/____/          \::::::::/    /                  \/____/                  \/____/                  \/____/               /:::/    /
                               \::::::/    /                                                                                          /:::/    /
                                \::::/    /                                                                                          /:::/    /
                                 \::/____/                                                                                           \::/    /
                                  ~~                                                                                                  \/____/
*/
#include<bits/stdc++.h>
#define int long long
#define ME0(X) memset(X,0,sizeof(X))
#define debug(x) std::cout << "debug_" << __LINE__ << (x) << '\n'
#define pii pair<int, int>
#define mii map<int, int>
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pb push_back
#define pqueue priority_queue
using namespace std;
using u128 = unsigned __int128; using i128 = __int128; using u64 = unsigned long long; using u32 = unsigned int;
const int MOD = 1e9 + 7, MAXN = 2e5 + 7, INF = 1e18 + 7;
mt19937 mt;
int qpow(int a, int b) {int res = 1; for(; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD; return res;}
int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int exgcd(int a, int b, int &x, int &y) {return !b ? (x = 1, y = 0, a) : (exgcd(b, a % b, y, x), y -= a / b * x, a);}

int fac[MAXN], inv[MAXN];

void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = inv[i-1] * qpow(i, MOD - 2) % MOD;
    }
}

int C(int n, int m) {
    if (n < m) return 0;
    else return fac[n] * inv[m] % MOD * inv[n-m] % MOD;
}

int c[4];

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        c[x % 3]++;
        sum += x;
    }
    if (sum % 3 == 0 || abs(c[1] - c[2]) > 3) {
        cout << "0\n";
        return;
    }
    int ans = C(c[0] + c[1] + c[2] - 1, c[0]) % MOD * fac[c[0]] % MOD * fac[c[1]] % MOD * fac[c[2]] % MOD;
    cout << ans;
}   

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
    init();
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}