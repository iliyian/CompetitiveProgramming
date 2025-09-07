#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int p = a[0];
  std::cout << "L";
  int l = 1, r = n - 1;
  while (l < r) {
    if (std::min(a[l], a[r]) > p) {
      if (a[l] < a[r]) {
        std::cout << "RL";
        p = a[l];
      } else {
        std::cout << "LR";
        p = a[r];
      }
    } else if (std::max(a[l], a[r]) < p) {
      if (a[l] < a[r]) {
        std::cout << "LR";
        p = a[r];
      } else {
        std::cout << "RL";
        p = a[l];
      }
    } else {
      std::cout << "LR";
      p = a[r];
    }
    l++, r--;
  }
  if (l == r) {
    std::cout << "L";
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}