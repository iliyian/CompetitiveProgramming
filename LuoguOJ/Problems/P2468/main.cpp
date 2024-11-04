#include <bits/stdc++.h>
#define lc seg[p].ls
#define rc seg[p].rs
#define mid (s + t) / 2

constexpr int N = 5e5;
int n, m, q;

std::vector<std::vector<int>> a;
std::vector<int> rt(N + 1);

struct Seg {
  int ls, rs;
  int sum, siz;
} seg[int(1.5e7)];

int cnt = 0;

void update(int &p, int s, int t, int pre, int c) {
  p = ++cnt;
  seg[p] = seg[pre];
  seg[p].sum += c, seg[p].siz++;
  if (c <= mid) update(lc, s, mid, p, c);
  else update(rc, mid + 1, t, p, c);
}

void query(int s, int t, int p, int c) {

}

void solve1() {
  for (int i = 1; i <= n; i++) {
    update(rt[i], 1, 1000, rt[i - 1], a[1][i]);
  }
  while (q--) {
    int r1, c1, r2, c2, h;
    std::cin >> r1 >> c1 >> r2 >> c2 >> h;
    if (seg[rt[c2]].sum - seg[rt[c1 - 1]].sum < h) {
      std::cout << "Poor QLW\n";
      continue;
    }
    int ans = query(1, 1000, rt[c2], h);
  }
}

void solve2() {
  std::vector<std::vector<std::vector<int>>> b(n + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(1001)));
  std::vector<std::vector<std::vector<int>>> cnt(n + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(1001)));
  for (int k = 1; k <= 1000; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        b[i][j][k] = (a[i][j] >= k) * a[i][j];
        cnt[i][j][k] = (a[i][j] >= k);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        b[i][j][k] += b[i - 1][j][k];
        cnt[i][j][k] += cnt[i - 1][j][k];
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        b[i][j][k] += b[i][j - 1][k];
        cnt[i][j][k] += cnt[i][j - 1][k];
      }
    }
  }
  while (q--) {
    int r1, c1, r2, c2, h;
    std::cin >> r1 >> c1 >> r2 >> c2 >> h;
    auto check = [&](const int &x) {
      return b[r2][c2][x] - b[r2][c1 - 1][x] - b[r1 - 1][c2][x] + b[r1 - 1][c1 - 1][x] >= h;
    };
    if (!check(1)) {
      std::cout << "Poor QLW\n";
      continue;
    }
    auto x = *std::ranges::partition_point(std::views::iota(1, 1001), check);
    int need = h - (b[r2][c2][x] - b[r2][c1 - 1][x] - b[r1 - 1][c2][x] + b[r1 - 1][c1 - 1][x]);
    int cur = cnt[r2][c2][x] - cnt[r2][c1 - 1][x] - cnt[r1 - 1][c2][x] + cnt[r1 - 1][c1 - 1][x];
    std::cout << cur + (need + x - 2) / (x - 1) << '\n';
  }
}

int main() {
  freopen("main.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n >> m >> q;
  a.assign(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  if (n == 1) solve1();
  else solve2();
  return 0;
}