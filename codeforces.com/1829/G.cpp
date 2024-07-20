// date: 2024-07-19 09:40:21
// tag: 数学

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 1414 * 1414;

std::vector<int> s(N + 1), t(N + 1), r(N + 1), c(N + 1);

int query(int l, int r) {
  if (l > r || !l || !r) return 0;
  return s[r] - s[l - 1];
}

int find(int x, int y) {
  return t[x] + y;
  // if (!m.count({x, y})) return 0;
  // return m[{x, y}];
}

void solve() {
  int n;
  std::cin >> n;
  int ans = s[find(r[n], r[n])], x = c[n], y = c[n];
  for (int i = r[n]; i >= 1; i--) {
    ans -= query(find(i, 1), find(i, x - 1)) + query(find(i, y + 1), find(i, i));
    x--;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int R = 1, C = 1, tmp = 0;
  for (int i = 1; i <= N; i++) {
    s[i] += s[i - 1] + i * i;
    r[i] = R, c[i] = C;
    t[R] = tmp;
    // if (i == N) {
    //   std::cout << R << ' ' << C << '\n';
    // }
    if (C == R) {
      R++;
      C = 1;
      tmp = i;
    } else {
      C++;
    }
  }

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}