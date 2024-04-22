// date: 2024-04-22 22:43:48
// tag: 二分，枚举

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  vector<int> len = {-1}, c = {-1};
  for (int i = 1; i <= n; i++) {
    if (cnt[i]) {
      len.push_back(cnt[i]);
      c.push_back(i);
    }
  }
  vector<int> s(c.size());
  for (int i = 1; i < c.size(); i++) {
    s[i] = s[i - 1] + len[i];
  }
  auto up = [&](int x) {
    return upper_bound(s.begin(), s.end(), x) - s.begin();
  };
  auto upbit = [](int x) -> int {
    for (int i = 20; i >= 0; i--) {
      if (x >> i & 1) {
        return i;
      }
    }
    return 0;
  };
  auto getsum = [&](int l, int r) {
    return s[r] - s[l - 1];
  };
  int ans = INT_MAX;
  for (int i = 0; i <= 20; i++) {
    int x = up(1 << i) - 1;
    for (int j = 0; j <= 20; j++) {
      int y = up(s[x] + (1 << j)) - 1;

      int r = getsum(y + 1, c.size() - 1);
      int z = upbit(r);
      if (r & ((1 << z) - 1)) {
        z++;
      }
      ans = min(ans,
        (int)((1 << z) + (1 << i) + (1 << j) - s[c.size() - 1]));
      if (1) {
        // cout << 't' << ' ';
      }
    }
  }
  cout << ans << '\n';
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