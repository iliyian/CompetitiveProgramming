#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string s, t;
  std::cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    if (isupper(s[i])) s[i] = tolower(s[i]);
  }
  for (int i = 0; i < t.size(); i++) {
    if (isupper(t[i])) t[i] = tolower(t[i]);
  }
  auto check = [&](std::string &s, std::string &t) {
    if (s.size() != t.size()) return false;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
      cnt += s[i] == t[i];
    }
    return cnt >= 4;
  };
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + 1; j < s.size(); j++) {
      std::swap(s[i], s[j]);
      if (check(s, t)) {
        std::cout << "how pay\n";
        return;
      }
      std::swap(s[i], s[j]);
    }
  }
  std::cout << "bull pay\n";
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