#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  std::vector<int> cnt(26);
  for (char ch : str) {
    cnt[ch - 'a']++;
  }
  int mn = 0, mx = 0;
  while (!cnt[mn]) mn++;
  for (int i = 0; i < 26; i++) {
    if (!cnt[i]) continue;
    if (cnt[i] >= cnt[mx]) mx = i;
    if (cnt[i] < cnt[mn]) mn = i;
  }
  for (int i = 0; i < n; i++) {
    if (str[i] - 'a' == mn) {
      str[i] = mx + 'a';
      break;
    }
  }
  std::cout << str << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
