#include <bits/stdc++.h>
// #define int long long

signed main() {
  // std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  // std::cin >> n;
  scanf("%d\n", &n);
  std::vector<std::array<int, 3>> a(n);
  int h;
  char s;
  for (int i = 0; i < n; i++) {
    // std::cin >> h >> s;
    scanf("%d %c\n", &h, &s);
    if (s == 'm') {
      a[i] = {-1, h, i};
    } else {
      a[i] = {1, -h, i};
    }
  }
  std::sort(a.begin(), a.end());
  std::vector<int> ans(n);
  int i = 0;
  for (auto j : a) {
    ans[j[2]] = ++i;
  }
  for (auto i : ans) {
    printf("%d ", i);
    // std::cout << i << ' ';
  }
  return 0;
}