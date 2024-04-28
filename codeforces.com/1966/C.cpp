#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  int ans = 0;
  if (a.size() == 1) {
    cout << "Alice" << '\n';
    return;
  }
  if (a.front() != 1) {
    cout << "Alice" << '\n';
    return;
  }
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i + 1] != a[i] + 1) {
      cout << (i % 2 ? "Alice" : "Bob") << '\n';
      return;
    }
  }
  cout << (a.size() % 2 ? "Alice" : "Bob") << '\n';
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