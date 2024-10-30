#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    s.insert(x);
  }
  std::vector<int> ans;
  int cur = 0;
  while (s.size() >= 2) {
    int x = *s.begin();
    int y = *s.rbegin();
    if ((x + y) % 2) {
      std::cout << -1 << '\n';
      return;
    }
    ans.push_back((x + y) / 2);
    if (ans.size() > 40) {
      break;
    }
    std::set<int> ss;
    for (auto i : s) {
      ss.insert(std::abs(i - (x + y) / 2));
    }
    s = ss;
  }
  if (*s.begin()) {
    ans.push_back(*s.begin() - cur); 
  }
  if (ans.size() > 40) {
    std::cout << -1 << '\n';
    return;
  }

  std::cout << ans.size() << '\n';
  for (auto i : ans) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
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