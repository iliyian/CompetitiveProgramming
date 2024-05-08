// date: 2024-05-05 23:16:47
// tag: 构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  vector<int> cnt(26);
  string str;
  cin >> n;
  for (int i = 0; i <= n * 2; i++) {
    cin >> str;
    for (auto ch : str) {
      cnt[ch - 'a']++;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] && cnt[i] % 2) {
      cout << char(i + 'a') << '\n';
      return;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}