#include <bits/stdc++.h>
using namespace std;

void solve() {
  std::array<int, 3> a;
  for (int i = 0; i < 3; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  int ans = a[1] - a[0] + a[2] - a[0] + a[2] - a[1];
  std::cout << std::max(0, ans - 4) << '\n';
}

int main() {
  freopen("C.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}