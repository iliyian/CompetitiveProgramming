#include <bits/stdc++.h>
#define int long long

void solve() {
  std::vector<std::string> a(8);
  std::vector<int> b(8);
  for (int i = 0; i < 8; i++) {
    std::cin >> a[i] >> b[i];
  }
  int i = 0, j = 4;
  for (int k = 0; k < 4; k++) {
    if (b[k] > b[i]) {
      i = k;
    }
  }
  for (int k = 4; k < 8; k++) {
    if (b[k] > b[j]) {
      j = k;
    }
  }
  if (b[i] > b[j]) std::swap(i, j);
  std::cout << a[j] << " beats " << a[i] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}