// date: 2024-05-10 16:16:59
// tag: tmd，什么是二维数点啊艹，写不来了，+800了都

// date: 2024-06-03 23:38:25
// tag: 前缀和，二维权值数点，数论，构造

#include <bits/stdc++.h>
#define int long long
#define N ((int)2e5)
using namespace std;

vector<int> d(N + 1);

void add(int x, int c) {
  for (int i = x; i <= N; i += i & -i) {
    d[i] += c;
  }
};

int query(int x) {
  int ans = 0;
  for (int i = x; i > 0; i -= i & -i) {
    ans += d[i];
  }
  return ans;
};

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

  vector<array<int, 3>> a;
  for (int i = 3; i <= N; i++) {
    for (int j = 0; j < fac[i].size(); j++) {
      // bad only
      a.push_back({fac[i][j], i, max(0ll, signed(fac[i].size()) - j - 2)});
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
    if (x[1] != y[1]) return x[1] < y[1];
    return x[0] < y[0];
  });

  vector<int> ans(q + 1);
  int idx = 0;
  for (int i = 1; i <= q; i++) {
    auto [l, r, id] = ask[i];
    while (idx < a.size() && a[idx][1] <= r) {
      add(a[idx][0], a[idx][2]);
      idx++;
    }
    int len = r - l + 1;
    ans[id] = len * (len - 1) * (len - 2) / 6;
    ans[id] -= max(0ll, r / 6 - (l - 1) / 3);
    ans[id] -= max(0ll, r / 15 - (l - 1) / 6);
    ans[id] -= query(r) - query(l - 1);
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}