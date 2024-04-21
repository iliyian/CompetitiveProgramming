#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> q;
  for (int i = 1; i <= m; i++) {
    int c;
    char d;
    cin >> c >> d;
    if (d == '0') {
      x = (x + c) % n;
      if (x == 0) x = n;
    } else if (d == '1') {
      x = (x - c + n) % n;
      if (x == 0) x = n;
    } else {
      q.push_back(c);
    }
  }

  vector<int> vis(n * 2 + 1);
  vis[0] = 0;
    

  vector<int> vis(n + 1);
  if (s.empty()) vis[x] = true;
  for (auto i : s) {
    int p = (i + x + n) % n;
    if (p == 0) p = n;
    vis[p] = true;
  }
  vector<int> ans;
  for (int i = 1; i <= n * 2; i++) {
    if (vis[i]) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
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