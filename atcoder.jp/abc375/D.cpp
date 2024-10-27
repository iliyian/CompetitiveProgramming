#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("D.in", "r", stdin);
  std::string s;
  std::cin >> s;
  s = '#' + s;
  int n = s.size() - 1;
  std::vector<int> a(26), cnt(26);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[s[i] - 'A'];
    for (int j = 0; j < 26; j++) {
      a[j] += cnt[j];
    }
    cnt[s[i] - 'A']++;
  }
  std::cout << ans << '\n';
  return 0;
}