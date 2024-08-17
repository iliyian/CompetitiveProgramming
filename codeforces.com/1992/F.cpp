// date: 2024-08-12 14:49:59
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 2e5;

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::set<int> s;
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    std::vector<int> tmp;
    for (auto j : s) {
      if (x % (j * a[i]) == 0) {
        tmp.push_back(j * a[i]);
      }
    }
    for (auto j : tmp) {
      s.insert(j);
    }
    if (s.count(x)) {
      ans++;
      s.clear();
    }
    if (x % a[i] == 0) {
      s.insert(a[i]);
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}