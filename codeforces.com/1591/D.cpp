// date: 2024-04-12 21:17:54
// tag: 树状数组频繁清空的小技巧，排序与逆序对

#include <bits/stdc++.h>
#define int long long
#define N 500000
using namespace std;

vector<int> d(N + 5 << 2), cnt(N + 5 << 2);

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  fill(d.begin(), d.begin() + (n + 5 << 2), 0);
  fill(cnt.begin(), cnt.begin() + (n + 5 << 2), 0);
  bool f = false;
  auto add = [&](int x) {
    for (int i = x; i <= n; i += i & -i) {
      d[i]++;
    }
  };
  auto query = [&](int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
      sum += d[i];
    }
    return sum;
  };
  int c = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    c += query(n) - query(a[i]);
    add(a[i]);
    if (++cnt[a[i]] >= 2) {
      f = true;
    }
  }
  if (f || c & 1 ^ 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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