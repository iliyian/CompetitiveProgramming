// date: 2024-06-27 19:16:31
// tag: 分治，dp，位运算

#include <bits/stdc++.h>
#define int long long
#define mod ((int)1e9 + 7)
using namespace std;

struct Info {
  int l = 0, r = 0, len = 0, ans = 0;
};

Info operator + (const Info &a, const Info &b) {
  if (a.len == 0) {
    return b;
  }
  if (b.len == 0) {
    return a;
  }
  Info c;
  c.l = (a.l == a.len ? a.len + b.l : a.l) % mod;
  c.r = (b.r == b.len ? b.len + a.r : b.r) % mod;
  c.len = (a.len + b.len) % mod;
  c.ans = ((a.ans + b.ans) % mod + a.r * b.l) % mod;
  return c;
}

vector<vector<Info>> f(62, vector<Info>(62));

Info get(int n, int k) {
  if (k < 0) return {0, 0, 1ll << n, 0};
  return f[n][k];
};

void solve() {
  int n, k;
  cin >> n >> k;
  int c = 0;
  Info ans;
  for (int i = 60; i >= 0; i--) {
    if (n >> i & 1ll) {
      ans = ans + get(i, k - c);
      c++;
    }
  }
  cout << ans.ans << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  for (int i = 0; i <= 60; i++) {
    f[0][i] = {1, 1, 1, 1};
  }

  for (int i = 1; i <= 60; i++) {
    for (int k = 0; k <= 60; k++) {
      f[i][k] = get(i - 1, k) + get(i - 1, k - 1);
    }
  }

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}