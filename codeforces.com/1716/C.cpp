// date: 2024-05-11 19:17:46
// tag: 三分，谁能想到tmd三分还要在[l-3,r+3]的范围里再搜一次？
// 谁能想到这函数还tmd可能不止一个峰？也许？
// 以及为什么<=改成<就不行了？

#include <bits/stdc++.h>
#define int long long
#define N 200000
using namespace std;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, 1};

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n + 1));
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  auto check = [&](int mid) {
    if (mid < 1 || mid > n) return LLONG_MAX;
    int cx = 0, cy = 1, d = 0, t = 0, dir = 1;
    bitset<(N + 5) << 1> vis;
    while (cy <= n && !vis[cx * n + cy]) {
      vis[cx * n + cy] = true;

      if (a[cx][cy] > t) t = a[cx][cy] + 1;
      else t++;
      if (cx == 0 && cy == 1) t = 0;

      if (cy >= mid) {
        if (cy == n && dir == 1) {
          dir = -1;
          cx ^= 1;
          continue;
        }
        cy += dir;
      } else {
        cx += dx[d], cy += dy[d];
        d = (d + 1) % 4;
      }
    }
    return t;
  };
  int l = 1, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int lmid = mid - 1, rmid = mid + 1;
    if (check(lmid) <= check(rmid)) r = mid;
    else l = mid;
  }
  int ans = INT_MAX;
  for (int i = l - 3; i <= r + 3; i++) {
    ans = min(ans, check(i));
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