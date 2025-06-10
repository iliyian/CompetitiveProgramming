#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string s, t;
  std::cin >> s >> t;
  int cnt = 1;
  if (s.front() != t.front()) {
    std::cout << "NO\n";
    return;
  }
  std::vector<int> a, b;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1]) {
      a.push_back(cnt);
      cnt = 0;
    }
    cnt++;
  }
  a.push_back(cnt);
  cnt = 1;
  for (int i = 1; i < t.size(); i++) {
    if (t[i] != t[i - 1]) {
      b.push_back(cnt);
      cnt = 0;
    }
    cnt++;
  }
  b.push_back(cnt);
  cnt = 1;
  if (a.size() != b.size()) {
    std::cout << "NO\n";
    return;
  }
  for (int i = 0; i < a.size(); i++) {
    if (b[i] < a[i] || b[i] > a[i] * 2) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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