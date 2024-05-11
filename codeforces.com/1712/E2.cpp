// date: 2024-05-10 16:16:59
// tag: tmd，什么是二维数点啊艹，写不来了，+800了都

#include <bits/stdc++.h>
#define int long long
#define N ((int)2e5)
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E2.in", "r", stdin);
  freopen("E2.out", "w", stdout);

  vector<vector<int>> fac(N + 1);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j * i <= N; j++) {
      fac[j * i].push_back(i);
    }
  }

  int q;
  cin >> q;
  vector<array<int, 3>> ask(q + 1);
  for (int i = 1; i <= q; i++) {
    cin >> ask[i][0] >> ask[i][1];
    ask[i][2] = i;
  }
  sort(ask.begin() + 1, ask.end(), [&](const array<int, 3> &x, const array<int, 3> &y) {
    return x[1]
  });

  for (int i = 1; i <= q; i++) {
    auto [l, r, _] = ask[i];

  }

  return 0;
}