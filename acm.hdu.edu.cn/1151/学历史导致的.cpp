#include <bits/stdc++.h>
#define int long long

std::string a[] = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
std::string b[] = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};

std::map<std::string, int> mp;

void solve() {
  std::string str;
  std::cin >> str;
  std::cout << mp[str] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;

  int x = 0, y = 0;
  for (int i = 1984; i <= 2043; i++) {
    mp[a[x] + b[y]] = i;
    x = (x + 1) % 10;
    y = (y + 1) % 12;
  }

  while (t--) {
    solve();
  }
  return 0;
}