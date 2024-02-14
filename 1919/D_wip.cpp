#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 2), l(n + 2), r(n + 2);
  vector<bool> in(n + 2);
  queue<int> q;
  int cnt = 0;
  auto check = [&](const int &x) {
    if (x < 1 || x > n || in[x]) {
      return false;
    }
    return a[l[x]] == a[x] - 1 || a[r[x]] == a[x] - 1;
  };
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l[i] = i - 1, r[i] = i + 1;
    cnt += a[i] == 0;
    if (check(i)) {
      in[i] = true;
      q.push(i);
    }
  }
  if (cnt != 1) {
    cout << "NO\n";
    return;
  }
  while (!q.empty()) {
    int x = q.front(); q.pop();
    int lx = l[x], rx = r[x];
    l[r[x]] = lx, r[l[x]] = rx;
    if (check(lx)) q.push(lx), in[lx] = true;
    if (check(rx)) q.push(rx), in[rx] = true;
  }
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) {
      cnt++;
    }
  }
  cout << (cnt == 1 ? "YES\n" : "NO\n");
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}