#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string s, t;
  std::cin >> s >> t;
  std::vector<int> ps(26, -1), pt(26, -1);
  for (int i = 1; i < s.size(); i++) {
    if (ps[s[i] - 'a'] == -1) {
      ps[s[i] - 'a'] = i;
    }
  }
  for (int i = t.size() - 2; i >= 0; i--) {
    if (pt[t[i] - 'a'] == -1) {
      pt[t[i] - 'a'] = i;
    }
  }
  int mn = INT_MAX, idx = -1;
  for (int i = 0; i < 26; i++) {
    if (ps[i] == -1 || pt[i] == -1) continue;
    if (ps[i] + t.size() - pt[i] < mn) {
      mn = ps[i] + t.size() - pt[i];
      idx = i;
    }
  }
  if (idx == -1) {
    std::cout << -1 << '\n'; 
  } else {
    std::cout << s.substr(0, ps[idx]) << t.substr(pt[idx], t.size() - pt[idx]) << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}