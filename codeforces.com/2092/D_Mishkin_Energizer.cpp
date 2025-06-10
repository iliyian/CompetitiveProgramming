// date: 2025-04-02 17:42:32
// tag: tmd傻逼了，奇偶搞错了，草！！！

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  char ch[3] = {'L', 'I', 'T'};
  int cnt[128] {};
  str = '#' + str;
  for (int i = 1; i <= n; i++) {
    cnt[str[i]]++;
  }
  if (cnt['L'] == n || cnt['I'] == n || cnt['T'] == n) {
    std::cout << -1 << '\n';
    return;
  }
  std::sort(ch, ch + 3, [&](char x, char y) {
    return cnt[x] < cnt[y];
  });
  char a = ch[0], b = ch[1], c = ch[2];
  std::cout << 2 * (cnt[c] - cnt[a] + cnt[b] - cnt[a]) << '\n';
  std::string t = str;
  // std::cerr << a << ' ' << b << ' ' << c << '\n';
  for (int i = 1; i <= n; i++) {
    if (i > 1 && str[i - 1] != str[i] && str[i - 1] == c) {
      for (int j = 0; j < (cnt[c] - cnt[a]) * 2; j++) {
        std::cout << i - 1 << ' ';
        t.insert(t.begin() + i, (str[i] == ch[0]) ^ (j % 2 == 1) ? ch[1] : ch[0]);
      }
      break;
    }
    if (i < n && str[i + 1] != str[i] && str[i + 1] == c) {
      for (int j = 0; j < (cnt[c] - cnt[a]) * 2; j++) {
        std::cout << i + j << ' ';
        t.insert(t.begin() + i + j + 1, (str[i] == ch[0]) ^ (j % 2 == 1) ? ch[1] : ch[0]);
      }
      break;
    }
  }
  // std::cerr << t << '\n';
  // return;
  str = t;
  n = str.size() - 1;
  for (int i = 1; i <= n; i++) {
    if (i > 1 && str[i - 1] != str[i] && str[i - 1] == b) {
      for (int j = 0; j < (cnt[b] - cnt[a]) * 2; j++) {
        std::cout << i - 1 << ' ';
        t.insert(t.begin() + i, (str[i] == ch[0]) ^ (j % 2 == 1) ? ch[2] : ch[0]);
      }
      break;
    }
    if (i < n && str[i + 1] != str[i] && str[i + 1] == b) {
      for (int j = 0; j < (cnt[b] - cnt[a]) * 2; j++) {
        std::cout << i + j << ' ';
        t.insert(t.begin() + i + j + 1, (str[i] == ch[0]) ^ (j % 2 == 1) ? ch[2] : ch[0]);
      }
      break;
    }
  }
  std::cout << '\n';
  // std::cerr << t << '\n';
  // memset(cnt, 0, sizeof(cnt));
  // for (int i = 1; i < t.size(); i++) {
  //   cnt[t[i]]++;
  // }
  // std::cerr << cnt['L'] << ' ' << cnt['I'] << ' ' << cnt['T'] << '\n';
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