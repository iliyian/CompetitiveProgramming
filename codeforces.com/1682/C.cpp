// date: 2024-05-04 16:08:37
// tag: 构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int cnt1 = 0, cnt2 = 0;
  for (auto [k, v] : cnt) {
    cnt1 += v == 1;
    cnt2 += v > 1;
  }
  cout << (cnt1 + 1) / 2 + cnt2 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}