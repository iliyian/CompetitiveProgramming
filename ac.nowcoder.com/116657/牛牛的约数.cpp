#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::map<int, int> mp, ans;
  int tot = 0;
  std::vector<int> b;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    b.push_back(a[i]);
    if (!mp.count(a[i])) {
      mp[a[i]] = i;
    }
  }
  std::ranges::sort(b);
  b.erase(std::unique(b.begin(), b.end()), b.end());
  std::ranges::reverse(b);
  std::set<int> s;
  for (auto i : b) {
    auto t = s;
    for (auto v : s) {
      if (v % i == 0) {
        break;
      }
      ans[v] = i;
      t.erase(v);
    }
    t.insert(i);
    s = t;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << (mp.count(ans[a[i]]) ? mp[ans[a[i]]] : -1) << ' ';
  }
  std::cout << '\n';
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