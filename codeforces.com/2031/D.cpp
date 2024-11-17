#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> pa(n + 1), siz(n + 1, 1), mx(n + 1);
  std::iota(pa.begin(), pa.end(), 0);
  auto find = [&](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    mx[y] = std::max(mx[y], mx[x]);
    siz[y] += siz[x];
  };
  std::stack<int> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mx[i] = a[i];
    while (!s.empty() && mx[find(find, s.top())] > a[i]) {
      int u = s.top(); s.pop();
      merge(u, i);
    }
    s.push(i);
  }
  for (int i = 1; i <= n; i++) {
    std::cout << mx[find(find, i)] << ' ';
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
};