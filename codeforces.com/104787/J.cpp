#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("J.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, W;
  std::cin >> n >> W;
  std::vector<int> cnt(14);
  std::vector<std::vector<int>> f(14, std::vector<int>(W + 1, INT_MAX));
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    cnt[x]++;
  }
  std::sort(cnt.begin() + 1, cnt.end(), std::greater<>());
  std::vector<int> v;
  for (int i = 1; i <= 13; i++) {
    if (!cnt[i]) continue;
    bool f = false;
    for (int &j : v) {
      if (j >= cnt[i]) {
        j -= cnt[i];
        f = true;
        break;
      }
    }
    if (!f) {
      v.push_back(W - cnt[i]);
    }
  }
  // for (int j : v) {
  //   std::cout << j << '\n';
  // }
  std::cout << v.size() << '\n';
  return 0;
}