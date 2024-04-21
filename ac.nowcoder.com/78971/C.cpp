#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

char change(char c) {
  if (isdigit(c)) {
    return c - '0';
  }
  return c - 'A' + 10;
}

void solve() {
  int n, p, q;
  cin >> n >> p >> q;
  vector<int> nums(n + 1);
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    for (int j = str.size() - 1; j >= 0; j--) {
      nums[i] += change(str[j]) * pow(p, str.size() - 1 - j);
    }
  }
  vector<vector<int>> a(n + 1, vector<int>({0}));
  int w = 0, l = 0, r = INT_MAX;
  for (int i = 1; i <= n; i++) {
    int cur = nums[i];
    while (cur) {
      a[i].push_back(cur % q);
      cur /= q;
    }
    w = max(w, (int)(a[i].size()));
  }
  for (int i = 1; i <= n; i++) {
    while (a[i].size() < w) {
      a[i].push_back(a[i].back());
    }
  }
  auto in = [&w, &n](int x, int y) {
    return x >= 1 && x <= n && y < w && y >= 1;
  };
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 5 - w + 1; j <= 5; j++) {
  //     cerr << a[i][j] << " \n"[j == 5];
  //   }
  // }

  auto check = [&](int mid) -> bool {
    vector<vector<bool>> vis(n + 1, vector<bool>(6));
    auto dfs = [&](auto self, int x, int y) -> bool {
      if (!in(x, y) || a[x][y] > mid || vis[x][y]) return false;
      vis[x][y] = true;
      if (x == n && y == 1) return true;
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (self(self, xx, yy)) {
          return true;
        }
      }
      return false;
    };
    int sx = 1, sy = w - 1;
    return dfs(dfs, sx, sy);
  };
  int ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
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