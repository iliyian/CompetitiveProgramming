#include <bits/stdc++.h>
#define int unsigned long long

signed main() {
  int n, b;
  std::cin >> n >> b;
  std::vector<std::pair<int, int>> a;

  for (int i = 2; i * i <= b; i++) {
    if (b % i == 0) {
      int cnt = 0;
      while (b % i == 0) b /= i, cnt++;
      a.push_back({i, cnt});
    }
  }
  if (b > 1) {
    a.push_back({b, 1});
  }
  std::vector<int> ans(a.size());
  for (int i = 0; i < a.size(); i++) {
    int t = n;
    while (t) {
      ans[i] += t / a[i].first;
      t /= a[i].first;
    }
    ans[i] /= a[i].second;
  }
  std::cout << *std::min_element(ans.begin(), ans.end()) << '\n';
  return 0;
}