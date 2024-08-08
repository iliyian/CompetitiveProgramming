#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
    a[i].second = i;
  }
  std::sort(a.begin() + 1, a.end());
  std::cout << a[a.size() - 2].second << '\n';

  return 0;
}