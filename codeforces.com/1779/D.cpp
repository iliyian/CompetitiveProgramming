// date: 2024-06-17 23:05:02
// tag: 已经满足的地方不要求连续，即不要求操作

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<int, int> pos;
  vector<int> prv(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (a[i] != b[i]) {
      prv[i] = pos[b[i]];
      pos[b[i]] = i;
    }
  }
  int m;
  cin >> m;
  vector<int> x(m + 1);
  map<int, int> cnt;
  for (int i = 1; i <= m; i++) {
    cin >> x[i];
    cnt[x[i]]++;
  }

  for (int i = 1; i <= n; i++) {
    if (b[i] > a[i] || b[i] != a[i] && !cnt[b[i]]) {
      cout << "NO\n";
      return;
    }
  }

  vector<vector<int>> mx(n + 1, vector<int>(21));
  for (int i = 1; i <= n; i++) {
    mx[i][0] = b[i];
  }
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i + (1 << (j - 1)) <= n; i++) {
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
  }

  auto querymax = [&](int x, int y) {
    int len = __lg(y - x + 1);
    return max(mx[x][len], mx[y - (1 << len) + 1][len]);
  };

  sort(x.begin() + 1, x.end());
  x.erase(unique(x.begin() + 1, x.end()), x.end());
  for (int i = x.size() - 1; i >= 1; i--) {
    int he = x[i], cn = 1, v = cnt[x[i]];
    for (int cur = pos[x[i]]; prv[cur] != 0; cur = prv[cur]) {
      if (querymax(prv[cur], cur) > he) {
        cn++;
      }
    }
    if (cn > v) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}