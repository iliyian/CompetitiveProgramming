#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    
  }
  std::cout << *std::max_element(a.begin() + 1, a.end() - 1) + a.back() << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}