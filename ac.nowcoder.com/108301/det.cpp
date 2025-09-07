#include <bits/stdc++.h>
#define int long long
#define ME0(X) memset(X, 0, sizeof(X))
#define debug(x) std::cout << "debug_" << __LINE__ << (x) << '\n'
#define pii pair<int, int>
#define mii map<int, int>
#define umap unordered_map
#define pb push_back
#define pqueue priority_queue
using namespace std;
const int MOD = 1e9 + 7, MAXN = 2e5 + 7, INF = 1e18 + 7;
using u128 = unsigned __int128;
using i128 = __int128;
int qpow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = a * a % MOD)
    if (b & 1)
      res = res * a % MOD;
  return res;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int exgcd(int a, int b, int &x, int &y) {
  return !b ? (x = 1, y = 0, a) : (exgcd(b, a % b, y, x), y -= a / b * x, a);
}

void solve() {}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  constexpr double EPS = 1E-9;

  int n;
  cin >> n;
  vector<vector<double>> a(n, vector<double>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  double det = 1;
  for (int i = 0; i < n; ++i) {
    int k = i;
    for (int j = i + 1; j < n; ++j)
      if (abs(a[j][i]) > abs(a[k][i]))
        k = j;
    if (abs(a[k][i]) < EPS) {
      det = 0;
      break;
    }
    swap(a[i], a[k]);
    if (i != k)
      det = -det;
    det *= a[i][i];
    for (int j = i + 1; j < n; ++j)
      a[i][j] /= a[i][i];
    for (int j = 0; j < n; ++j)
      if (j != i && abs(a[j][i]) > EPS)
        for (int k = i + 1; k < n; ++k)
          a[j][k] -= a[i][k] * a[j][i];
  }

  cout << (int)det;
  return 0;
}