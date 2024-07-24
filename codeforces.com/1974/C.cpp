#include <bits/stdc++.h>
#define int long long
using namespace std;

int h(int a, int b) {
  return a * 1e7 + b;
}

__int128 h(int a, int b, int c) {
  return __int128(a) * __int128(1e14) + __int128(b) * 1e7 + c;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  array<unordered_map<int, int>, 3> cnt;
  unordered_map<int, unordered_map<int, int>> tuplecnt;
  int ans = 0;
  for (int i = 1; i <= n - 2; i++) {
    array<int, 3> tupl;
    for (int j = 0; j < 3; j++) {
      tupl[j] = a[i + j];
    }
    int x = h(tupl[1], tupl[2]);
    int y = h(tupl[0], tupl[2]);
    int z = h(tupl[0], tupl[1]);

    int tuplh = h(tupl[1], tupl[2]);

    ans += cnt[0][x] + cnt[1][y] + cnt[2][z] - 3 * tuplecnt[tupl[0]][tuplh];
    cnt[0][x]++;
    cnt[1][y]++;
    cnt[2][z]++;
    tuplecnt[tupl[0]][tuplh]++;
  }

  cout << ans << '\n';
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