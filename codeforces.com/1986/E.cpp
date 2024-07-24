#include <bits/stdc++.h>
#define int long long
#define N ((int)1e5)
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(a.begin() + 1, a.end());
  a.erase(unique(a.begin() + 1, a.end()), a.end());
  vector<int> b;
  for (int i = 1; i < a.size(); i++) {
    if (cnt[a[i]] % 2) {
      b.push_back(a[i]);
    }
  }
  if (b.size() == 1 || b.size() == 0) {
    cout << 0 << '\n';
    return;
  }

  sort(b.begin(), b.end(), [&](const int &x, const int &y) {
    if (x % k != y % k) {
      return x % k < y % k;
    }
    return x < y;
  });
  
  bitset<N + 1> vis;
  int ans = 0, fail = 0;
  for (int i = 0; i < b.size(); i++) {
    if (vis[i]) continue;
    for (int j = i + 1; j < b.size(); j++) {
      if ((b[j] - b[i]) % k == 0) {
        ans += (b[j] - b[i]) / k;
        vis[i] = true;
        vis[j] = true;
        break;
      }
    }
    if (!vis[i]) {
      fail++;
    }
    if (fail >= 2) {
      cout << -1 << '\n';
      return;
    }
  }
  if (vis.count() < b.size() - 1) {
    cout << -1 << '\n';
    return;
  }

  if (vis.count() == b.size() - 1) {
    for (int i = 0; i < b.size(); i++) {
      if (!vis[i]) {
        int cur = ans;
        for (int j = i; j >= 2 && ((b[j - 2] % k) == (b[i] % k)); j -= 2) {
          int nxt = cur + (b[j] - b[j - 1]) / k - (b[j - 1] - b[j - 2]) / k;
          cur = nxt;
          ans = min(ans, cur);
        }
        break;
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}