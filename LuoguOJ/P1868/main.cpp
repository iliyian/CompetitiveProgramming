// date: 2024-03-16 14:42:26
// tag: 线性dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
  int l, r;
  bool operator < (const Node &b) const {
    if (r == b.r) return l < b.l;
    return r < b.r;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<Node> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r;
  }
  sort(a.begin() + 1, a.end());
  vector<int> dp(n + 1);

  for (int i = 1; i <= n; i++) {
    int idx = lower_bound(a.begin() + 1, a.end(), Node{INT_MIN, a[i].l})
      - a.begin() - 1;
    dp[i] = max(dp[i - 1], dp[idx] + a[i].r - a[i].l + 1);
  }
  cout << dp[n] << '\n';

  return 0;
}