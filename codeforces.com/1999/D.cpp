#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  std::string s, t;
  std::cin >> s >> t;
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    if (j < t.size() && (s[i] == t[j] || s[i] == '?')) {
      if (s[i] == '?') {
        s[i] = t[j];
      }
      j++;
    }
  }
  if (j < t.size()) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
  for (char &x : s) {
    if (x == '?') {
      x = 'a';
    }
  }
  std::cout << s << '\n';
}

int32_t main() {
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