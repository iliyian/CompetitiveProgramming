#include <bits/stdc++.h>
#define int long long

std::string NSWEI = "NSWEI";

int dx[] = {0, 0, -1, 1, 0}, dy[] = {1, -1, 0, 0, 0};
int dgx[] = {0, 0, -1, 0, 1}, dgy[] = {0, 1, 0, -1, 0};

void solve() {
  int n, m, sx, sy;
  std::cin >> n >> m >> sx >> sy;
  std::vector<int> x(m + 1), y(m + 1), p(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> p[i];
  }
  int q;
  std::cin >> q;
  int cur = 1;
  bool f = true;

  auto check = [&](int cx, int cy) -> int {
    int mnd = INT_MAX;
    if (cx < 1 || cx > n || cy < 1 || cy > n) return -1;
    for (int i = 1; i <= m; i++) {
      int curd = std::abs(cx - x[i]) + std::abs(cy - y[i]);
      if (curd <= p[i]) {
        return -1;
      }
      mnd = std::min(mnd, curd);
    }
    return mnd;
  };

  std::vector<char> ss(q + 1), cc(q + 1);
  for (int i = 1; i <= q; i++) {
    std::cin >> ss[i] >> cc[i];
  }

  for (int t = 1; t <= q; t++) {
    char s = ss[t], c = cc[t];
    int d = NSWEI.find(s);
    int xx = x[cur] + dx[d], yy = y[cur] + dy[d];
    if (xx < 1 || xx > n || yy < 1 || yy > n || xx == sx && yy == sy) {
      f = false;
      std::cout << "Illegal Operation!\n";
      goto end;
    }
    for (int i = 1; i <= m; i++) {
      if (i != cur && xx == x[i] && yy == y[i]) {
        f = false;
        std::cout << "Illegal Operation!\n";
        goto end;
      }
    }
    x[cur] = xx, y[cur] = yy;
    if (c == '+') p[cur]++;
    else if (c == '-') p[cur]--;
    if (p[cur] < 0) {
      f = false;
      std::cout << "Illegal Operation!\n";
      goto end;
    }
    std::cout << "Legal Operation!\n";

    int dir = -1, mxd = INT_MIN;
    for (int i = 0; i < 5; i++) {
      int xx = sx + dgx[i], yy = sy + dgy[i];
      int d = check(xx, yy);
      if (d == -1) {
        continue;
      }
      if (d > mxd) {
        mxd = d;
        dir = i;
      }
    }
    if (dir == -1) {
      std::cout << "Escape!\n";
      f = false;
      goto end;
    }
    int nx = sx + dgx[dir], ny = sy + dgy[dir];
    sx = nx, sy = ny;
    std::cout << sx << ' ' << sy << '\n';

    cur = cur % m + 1;
  }
  end:
  if (f) {
    std::cout << "Grandmaster General Kangaroo!\n";
  }
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