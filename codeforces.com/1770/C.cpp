// date: 2024-06-07 19:50:51
// tag: 数论，构造

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
  for (auto [k, v] : cnt) {
    if (v >= 2) {
      cout << "NO\n";
      return;
    }
  }
  // 特殊化，只考虑k=2，显然奇数和偶数数量不能都大于2
  for (int i = 2; i * 2 <= n; i++) {
    vector<int> cnt(i);
    for (int j = 1; j <= n; j++) {
      cnt[a[j] % i]++;
    }
    bool f = true;
    for (int j = 0; j < i; j++) {
      if (cnt[j] < 2) {
        f = false;
        break;
      }
    }
    if (f) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}