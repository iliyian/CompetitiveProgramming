// date: 2025-05-21 12:29:46
// tag: 构造，数学，图论

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> ans;
  ans.push_back(n);
  for (int i = n - 1; i >= 2; i--) {
    if (k >= i * (i - 1) / 2) {
      k -= i * (i - 1) / 2;
      ans.push_back(i);
    }
  }
  ans.push_back(1);
  // std::cerr << k << '\n';
  if (k != 1 && k != 0) {
    std::cout << "No\n";
    return;
  }
  for (auto i : ans) {
    std::cerr << i << '\n';
  }
  std::cout << "Yes\n";
  int cur = 1;
  for (int i = 0; i < ans.size() - 1; i++) {
    int pa = cur;
    for (int j = 0; j < ans[i] - ans[i + 1]; j++) {
      std::cout << pa << ' ' << ++cur << '\n';
    }
  }
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