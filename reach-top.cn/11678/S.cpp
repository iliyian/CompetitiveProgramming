#include <bits/stdc++.h>
#define int long long

int num(char x) {
  if (isdigit(x)) return x - '0';
  return 10 + x - 'A';
}

char ch(int x) {
  if (x <= 9) return x + '0';
  return x - 10 + 'A';
}

signed main() {
  freopen("S.in", "r", stdin);
  int n;
  std::cin >> n;
  std::vector<int> cnt(256);
  std::vector<std::string> s(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> s[i];
    int m = s[i].size();
    for (int j = 0; j < m; j += 2) {
      int cur = num(s[i][j]) * 16 + num(s[i][j + 1]);
      if (cur > 255) {
        std::cout << cur << '\n';
      }
      cnt[cur]++;
    }
  }
  std::vector<int> id(256);
  std::iota(id.begin(), id.end(), 0);
  std::stable_sort(id.begin(), id.end(), [&](const int &x, const int &y) {
    return cnt[x] > cnt[y];
  });
  for (int i = 0; i < 16; i++) {
    std::cout << ch(id[i] / 16) << ch(id[i] % 16);
  }
  std::cout << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < s[i].size(); j += 2) {
      int ans = 0, idx = num(s[i][j]) * 16 + num(s[i][j + 1]);
      for (int k = 0; k < 16; k++) {
        if (std::abs(id[k] - idx) < std::abs(id[ans] - idx)) {
          ans = k;
        }
      }
      std::cout << ch(ans);
    }
    std::cout << '\n';
  }
  return 0;
}