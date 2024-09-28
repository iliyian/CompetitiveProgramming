#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define pb push_back
#define REP(i, b, e) for (int i = (b); i < (int)(e); ++i)
#define over(x)                                                                \
  {                                                                            \
    cout << x << endl;                                                         \
    return;                                                                    \
  }
int n;
int a[400005], res[400005], lsteq[400005];
int st[400005][20];
int query(int l, int r) {
  int s = __lg(r - l + 1);
  return __gcd(st[l][s], st[r - (1 << s) + 1][s]);
}
void Main() {
  cin >> n;
  REP(i, 0, n) cin >> a[i];
  --n;
  if (!n)
    over(1) REP(i, 0, n) st[i][0] = llabs(a[i] - a[i + 1]);
  REP(j, 0, __lg(n)) {
    REP(i, 0, n - (1 << (j + 1)) + 1) {
      st[i][j + 1] = __gcd(st[i][j], st[i + (1 << j)][j]);
    }
  }
  lsteq[n] = n;
  for (int i = n - 1; i >= 0; --i)
    lsteq[i] = (a[i] == a[i + 1] ? lsteq[i + 1] : i);
  int ans = 1;
  int l = 0, r = 0;
  REP(i, 0, n) {
    l = max(l, lsteq[i]);
    r = max(r, l);
    while (r < n && __builtin_popcountll(query(l, r)) > 1)
      ++r;
    ans += n - r;
    ans += lsteq[i] - i + 1;
  }
  cout << ans << endl;
}
void TC() {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    Main();
    cout.flush();
  }
}
signed main() {
  return cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), TC(), 0;
}