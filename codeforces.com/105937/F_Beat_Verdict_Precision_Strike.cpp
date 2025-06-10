#include <bits/stdc++.h>
#define int long long

std::vector<int> R(20);

void solve() {
  int n;
  std::cin >> n;
  int l = 1, r = 1;
  while (R[r] < n) r++;
  while (l < r) {
    int mid = (l + r) / 2;
    std::cout << "? " << std::min(n, R[mid] + 1) << std::endl;
    int ans;
    std::cin >> ans;
    if (ans) r = mid;
    else l = mid + 1;
  }
  std::cout << "! " << std::min(R[l] / 2, n) << std::endl;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 1; i <= 19; i++) {
    R[i] = (R[i - 1] + 1) * 4;
    std::cerr << R[i] << ' ';
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}