#include <bits/stdc++.h>
#include <ranges>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  if (a == b) {
    std::cout << "Bob\n";
    return;
  }
  std::reverse(a.begin() + 1, a.end());
  if (a == b) {
    std::cout << "Bob\n";
    return;
  }
  std::cout << "Alice\n";
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