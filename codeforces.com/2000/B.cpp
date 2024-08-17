#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  s.insert(a[1]);
  for (int i = 2; i <= n; i++) {
    if (s.count(a[i] - 1) || s.count(a[i] + 1)) {
      s.insert(a[i]);
    } else {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}