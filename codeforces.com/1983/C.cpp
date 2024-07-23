#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::array<int, 3>> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][0];
    sum += a[i][0];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][1];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][2];
  }
  std::vector<int> id = {0, 1, 2};
  int avg = (sum - 1) / 3 + 1;
  do {
    int suma = 0, sumb = 0, sumc = 0;
    int p0 = 1;
    while (p0 <= n && suma < avg) suma += a[p0][id[0]], p0++;
    int p1 = n;
    while (p1 >= p0 && sumb < avg) sumb += a[p1][id[1]], p1--;
    for (int i = p0; i <= p1; i++) {
      sumc += a[i][id[2]];
    }
    if (suma >= avg && sumb >= avg && sumc >= avg) {
      std::vector<int> ans(6);
      ans[id[0] * 2] = 1;
      ans[id[0] * 2 + 1] = p0 - 1;
      ans[id[1] * 2] = p1 + 1;
      ans[id[1] * 2 + 1] = n;
      ans[id[2] * 2] = p0;
      ans[id[2] * 2 + 1] = p1;
      for (int i = 0; i < 6; i++) {
        std::cout << ans[i] << ' ';
      }
      std::cout << '\n';
      return;
    }
  } while (std::next_permutation(id.begin(), id.end()));
  std::cout << -1 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}