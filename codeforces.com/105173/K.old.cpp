#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("K.in", "r", stdin);
  int n;
  std::cin >> n;
  std::vector<std::array<int, 3>> a(n + 1);
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][0] >> a[i][1];
    a[i][2] = i;
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n - 1; i++) {
    if (a[i][0] == a[i + 1][0] && a[i][1] == a[i + 1][1]) {
      std::cout << -1 << '\n';
      return 0;
    }
  }
  std::stack<int> s;
  if (a[1][1]) {
    std::cout << -1 << '\n';
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    auto &[l, b, id] = a[i];
    // if (!s.empty() && b - a[s.top()][1] > 1) {
    //   std::cout << -1 << '\n';
    //   return 0;
    // }
    if (!s.empty() && a[s.top()][1] >= b) {
      int mx = a[s.top()][0];
      while (!s.empty() && a[s.top()][1] >= b) {
        int u = s.top(); s.pop();
        ans[a[u][2]] = mx;
      }
    }
    s.push(i);
  }
  std::vector<int> vec;
  while (!s.empty()) {
    vec.push_back(s.top()); s.pop();
  }
  int cnt = 0, lst = 0;
  while (!vec.empty()) {
    int u = vec.back(); vec.pop_back();
    ans[a[u][2]] = 1e6 - (cnt += a[lst][0] == a[u][0]);
    lst = u;
    if (ans[a[u][2]] < a[u][0]) {
      std::cout << -1 << '\n';
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}