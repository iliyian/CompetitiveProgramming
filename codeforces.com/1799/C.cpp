// date: 2024-07-05 11:20:50
// tag: 字符串，构造，推性质

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  std::string str;
  std::cin >> str;
  std::vector<int> cnt(26);
  for (char ch : str) {
    cnt[ch - 'a']++;
  }
  std::string ans(str.size(), '?');
  int l = 0, r = str.size() - 1;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < cnt[i] / 2 * 2; j += 2) {
      ans[l++] = ans[r--] = i + 'a';
    }
    if (cnt[i] & 1) {
      for (int j = i + 1; j < 26; j++) {
        if (cnt[j] == r - l) {
          for (int k = 0; k < (cnt[j] + 1) / 2; k++) {
            ans[l++] = j + 'a';
          }
          ans[l++] = i + 'a';
          while (r >= l) {
            ans[r--] = j + 'a';
          }
          goto out;
        }
      }
      for (int j = i + 1; j < 26; j++) {
        while (cnt[j]) {
          ans[l++] = j + 'a';
          cnt[j]--;
        }
      }
      ans[r] = i + 'a';
      goto out;
    }
  }
  out:
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}