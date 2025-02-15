#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> d(n + 1);
  auto add = [&](std::vector<int> &d, int x, int c) {
    for (int i = x; i <= n; i += i & -i) d[i] += c;
  };
  auto query = [&](std::vector<int> &d, int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  std::vector<int> A(n + 1), B(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    A[i] = query(d, a[i]);
    add(d, a[i], 1);
    B[i] = a[i] - 1 - A[i];
    // std::cerr << a[i] << ": " << A[i] << ' ' << B[i] << '\n';
    ans += std::min(A[i], B[i]);
  }
  std::vector<int> le(n + 1), ge(n + 1), eq(n + 1), le1(n + 1), ge1(n + 1);
  // 分别对应a_i<b_i-1, a_i>b_i+1, a_i==b_i, a_i==b_i-1, a_i==b_i+1
  int q;
  std::cin >> q;
  std::vector<std::pair<int, int>> ask(q);
  std::vector<std::vector<int>> req(n + 1);
  for (auto &[l, r] : ask) {
    std::cin >> l >> r;
    if (l > r) std::swap(l, r);
    int x = std::min(a[l], a[r]), y = std::max(a[l], a[r]);
    if (l == r) continue;
    if (l != r - 1) { //
      req[l].push_back(x - 1);
      req[l].push_back(y);
      req[r - 1].push_back(x - 1);
      req[r - 1].push_back(y);
    }
    req[l].push_back(a[r]);
    req[r].push_back(a[l]);
  }
  std::vector<std::map<int, int>> le_ans(n + 1), ge_ans(n + 1), eq_ans(n + 1), d_ans(n + 1), le1_ans(n + 1), ge1_ans(n + 1);
  std::fill(d.begin(), d.end(), 0);
  for (int i = 1; i <= n; i++) {
    if (A[i] < B[i] - 1) {
      add(le, a[i], 1);
    } else if (A[i] > B[i] + 1) {
      add(ge, a[i], 1);
    } else if (A[i] == B[i]) {
      add(eq, a[i], 1);
    } else if (A[i] == B[i] + 1) {
      add(ge1, a[i], 1);
    } else if (A[i] == B[i] - 1) {
      add(le1, a[i], 1);
    }
    add(d, a[i], 1);
    for (auto j : req[i]) {
      // if (i == 1) {
      //   std::cerr << "qwq";
      //   std::cerr << j << ' ';
      // }
      d_ans[i][j] = query(d, j);
      le_ans[i][j] = query(le, j);
      ge_ans[i][j] = query(ge, j);
      eq_ans[i][j] = query(eq, j);
      le1_ans[i][j] = query(le1, j);
      ge1_ans[i][j] = query(ge1, j);
    }
  }
  for (auto [l, r] : ask) {
    int x = a[l], y = a[r];
    if (l == r) {
      std::cout << ans << '\n';
      continue;
    }
    int t = ans;
    int al = A[l], bl = B[l], ar = A[r], br = B[r];
    t -= std::min(al, bl) + std::min(ar, br);
    al = d_ans[l][y];
    ar = d_ans[r][x];
    // std::cerr << al << ' ' << bl << ' ' << ar << ' ' << br << '\n';
    // std::cerr << x << ' ' << y << '\n';
    if (a[l] < a[r]) {
      al--;
      ar--;
    } else {
      ar--;
    }
    bl = y - 1 - al, br = x - 1 - ar;
    t += std::min(al, bl) + std::min(ar, br);
    // std::cerr << t << '\n';
    // std::cerr << al << ' ' << bl << ' ' << ar << ' ' << br << '\n';
    if (l == r - 1) {
      std::cout << t << '\n';
      continue;
    }
    if (x < y) {
      int cnt_le = le_ans[r - 1][y] - le_ans[l][y] - le_ans[r - 1][x - 1] + le_ans[l][x - 1];
      int cnt_ge = ge_ans[r - 1][y] - ge_ans[l][y] - ge_ans[r - 1][x - 1] + ge_ans[l][x - 1];
      int cnt_eq = eq_ans[r - 1][y] - eq_ans[l][y] - eq_ans[r - 1][x - 1] + eq_ans[l][x - 1];
      int cnt_le1 = le1_ans[r - 1][y] - le1_ans[l][y] - le1_ans[r - 1][x - 1] + le1_ans[l][x - 1];
      t -= cnt_eq;
      t -= cnt_le;
      t += cnt_ge;
      t -= cnt_le1;
    } else {
      std::swap(x, y);
      int cnt_le = le_ans[r - 1][y] - le_ans[l][y] - le_ans[r - 1][x - 1] + le_ans[l][x - 1];
      int cnt_ge = ge_ans[r - 1][y] - ge_ans[l][y] - ge_ans[r - 1][x - 1] + ge_ans[l][x - 1];
      int cnt_eq = eq_ans[r - 1][y] - eq_ans[l][y] - eq_ans[r - 1][x - 1] + eq_ans[l][x - 1];
      int cnt_ge1 = ge1_ans[r - 1][y] - ge1_ans[l][y] - ge1_ans[r - 1][x - 1] + ge1_ans[l][x - 1];
      // std::cerr << cnt_le << ' ' << cnt_ge << ' ' << cnt_eq << '\n';
      // std::cerr << le_ans[r][y] << ' ' << le_ans[l - 1][y] << ' ' << le_ans[r][x - 1] << ' ' << le_ans[l - 1][x - 1] << '\n';
      t -= cnt_eq;
      t += cnt_le;
      t -= cnt_ge;
      t -= cnt_ge1;
    }
    std::cout << t << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}