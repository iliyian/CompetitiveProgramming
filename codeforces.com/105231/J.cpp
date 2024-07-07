// date: 2024-07-02 19:59:52
// tag: 模拟

#include <bits/stdc++.h>
#define int long long
// using namespace std;

std::vector<std::pair<char, char>> terminal = {
  {'1', 'p'},
  {'9', 'p'},
  {'1', 's'},
  {'9', 's'},
  {'1', 'm'},
  {'9', 'm'},

  {'1', 'z'},
  {'2', 'z'},
  {'3', 'z'},
  {'4', 'z'},
  {'5', 'z'},
  {'6', 'z'},
  {'7', 'z'},
};

void solve() {
  std::map<std::pair<char, char>, int> cnt;
  for (int i = 0; i < 14; i++) {
    char n, c;
    std::cin >> n >> c;
    cnt[{n, c}]++;
  }
  int c = 0;
  for (auto [k, v] : cnt) {
    if (v >= 2) {
      c++;
    }
  }
  if (c == 7) {
    std::cout << "7 Pairs\n";
    return;
  }
  for (auto x : terminal) {
    if (!cnt[x]) {
      std::cout << "Otherwise\n";
      return;
    }
  }
  std::cout << "Thirteen Orphans\n";
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("J.in", "r", stdin);
  freopen("J.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}