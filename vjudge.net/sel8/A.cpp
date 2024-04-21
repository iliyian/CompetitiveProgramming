// date: 2023/12/24 15:01:14
// tag: 持续更新，没有什么算法技巧，智慧题

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  set<int> s;
  s.insert(0);
  for (int i = 0; i < k; i++) {
    int x = *s.begin();
    s.erase(s.begin());
    for (int j = 0; j < n; j++)
      s.insert(a[j] + x);
  }

  cout << *s.begin() << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}