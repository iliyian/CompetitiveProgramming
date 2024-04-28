#include <bits/stdc++.h>
#define N 1000000
using namespace std;

vector<int> bcnt(N + 1), acnt(N + 1), cnt(N + 1);

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int use = 0;
  vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i <= m) {
      acnt[a[i]]++;
    }
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    bcnt[b[i]]++;
  }

  vector<int> c = b;
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());

  bool prv = false;
  int cnt = 0, ans = 0;
  for (auto i : c) {
    cnt += min(acnt[i], bcnt[i]);
  }
  if (cnt >= k) {
    ans++;
    prv = true;
  }
  int l = 1, r = m;
  while (r <= n - 1) {
    l++, r++;
    if (a[l - 1] == a[r]) {
      ans += prv;
      continue;
    }

    cnt -= min(acnt[a[l - 1]], bcnt[a[l - 1]]);
    acnt[a[l - 1]]--;
    cnt += min(acnt[a[l - 1]], bcnt[a[l - 1]]);

    cnt -= min(acnt[a[r]], bcnt[a[r]]);
    acnt[a[r]]++;
    cnt += min(acnt[a[r]], bcnt[a[r]]);

    if (cnt >= k) {
      ans++;
      prv = true;
    } else {
      prv = false;
    }
  }
  cout << ans << '\n';

  for (int i = 1; i <= n; i++) {
    acnt[a[i]] = bcnt[a[i]] = 0;
  }
  for (int i = 1; i <= m; i++) {
    acnt[b[i]] = bcnt[b[i]] = 0;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}