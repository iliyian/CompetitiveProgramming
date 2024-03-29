// date: 2024-03-28 16:47:51
// tag: 贪心，思维，构造，乱搞

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> nxt(n * 2 + 1);
  int ans = 0;
  auto calc = [&](int x, int y) {
    int cnt = 0;
    vector<bool> vis(n * 2 + 1);
    for (int i = x + 1; i < y; i++) {
      if (nxt[i]) {
        if (!vis[nxt[i]]) {
          vis[i] = true;
          cnt++;
        } else {
          cnt--;
        }
      }
    }
    return cnt;
  };
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    nxt[x] = y;
    nxt[y] = x;
    ans += calc(x, y);
  }
  vector<int> r;
  for (int i = 1; i <= n * 2; i++) {
    if (!nxt[i]) {
      r.push_back(i);
    }
  }
  for (int i = 0; i < r.size() / 2; i++) {
    int j = i + r.size() / 2;
    int x = r[i], y = r[j];
    nxt[x] = y, nxt[y] = x;
    ans += calc(x, y);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}