// date: 2024-04-01 16:30:30
// tag: 构造
// 考虑到要构造的字符串很长，又考虑到这题必然不难，所以不可能用完a-z，
// 所以尽可能少即可

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 'a' << '\n';
    return;
  }
  for (int i = 0; i < n / 2; i++) {
    cout << 'a';
  }
  cout << 'b';
  if (n & 1) {
    cout << 'c';
  }
  for (int i = 0; i < n / 2 - 1; i++) {
    cout << 'a';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}