// date: 2024-07-01 14:43:35
// tag: 贪心，构造

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> pos, neg;
  bool f = false;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i]) f = true;
    if (a[i] >= 0) pos.push_back(a[i]);
    else neg.push_back(a[i]);
  }
  if (!f) {
    std::cout << "No\n";
    return;
  }
  std::cout << "Yes\n";
  int s = 0;
  std::vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (s > 0 && !neg.empty()) {
      // std::cout << neg.back() << ' ';
      s += neg.back();
      ans.push_back(neg.back());
      neg.pop_back();
    } else {
      // std::cout << pos.back() << ' ';
      s += pos.back();
      ans.push_back(pos.back());
      pos.pop_back();
    }
  }
  for (auto i : ans) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}