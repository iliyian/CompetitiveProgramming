// date: 2024-06-08 21:53:05
// tag: 存在多次操作可能

#include <bits/stdc++.h>
#define int long long
#define N 30
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<vector<char>>> a(k + 2, vector<vector<char>>(n + 1, vector<char>(m + 1)));
  vector<int> cnt(k + 2);
  for (int t = 1; t <= k + 1; t++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[t][i][j];
      }
    }
    for (int i = 2; i <= n - 1; i++) {
      for (int j = 2; j <= m - 1; j++) {
        bool f = true;
        for (int d = 0; d < 4; d++) {
          if (a[t][i + dx[d]][j + dy[d]] != a[t][i][j]) {
            f = false;
            break;
          }
        }
        if (f) {
          cnt[t]++;
        }
      }
    }
  }

  vector<int> id(k + 2);
  iota(id.begin() + 1, id.end(), 1);
  sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return cnt[x] < cnt[y];
  });
  // for (int i = 1; i <= k + 1; i++) {
  //   cout << id[i] << ' ' << cnt[id[i]] << '\n';
  // }
  // cout << '\n';
  vector<array<int, 3>> ans;
  cout << id[1] << '\n';
  for (int t = 2; t <= k + 1; t++) {
    if (cnt[id[t]] != cnt[id[t - 1]]) {
      for (int i = 2; i <= n - 1; i++) {
        for (int j = 2; j <= m - 1; j++) {
          if (a[id[t]][i][j] != a[id[t - 1]][i][j]) {
            ans.push_back({1, i, j});
          }
        }
      }
    }
    ans.push_back({{2, id[t]}});
  }
  cout << ans.size() << '\n';
  for (auto [op, x, y] : ans) {
    cout << op << ' ' << x << ' ';
    if (op == 1) cout << y;
    cout << '\n';
  }

  return 0;
}