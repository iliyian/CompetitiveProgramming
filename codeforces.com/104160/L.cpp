#include <bits/stdc++.h>
#define int long long

struct Node {
  int h = 0, atk = 0, cnt = 0;
};

std::array<double, 3> work(std::vector<Node> &a, std::vector<Node> &b) {
  int asiz = 0, bsiz = 0;
  for (int i = 0; i < a.size(); i++) asiz += a[i].h > 0;
  for (int i = 0; i < b.size(); i++) bsiz += b[i].h > 0;

  if (!asiz && !bsiz) return {0, 0, 1};
  if (!asiz) return {0, 1, 0};
  if (!bsiz) return {1, 0, 0};

  int now = -1;
  for (int i = 0; i < a.size(); i++) {
    if (a[i].h > 0 && (now == -1 || a[i].cnt < a[now].cnt)) {
      now = i;
    }
  }
  std::array<double, 3> ans = {0, 0, 0};
  for (int i = 0; i < b.size(); i++) {
    if (b[i].h <= 0) continue;
    // auto ai = a[now], bi = b[i];

    b[i].h -= a[now].atk;
    // b[i].cnt++;

    // if (b[i].h > 0) {
      a[now].h -= b[i].atk;
      a[now].cnt++;
    // }
    
    auto nxt = work(b, a);
    ans[0] += nxt[1] / bsiz, ans[1] += nxt[0] / bsiz, ans[2] += nxt[2] / bsiz;

    // a[now] = ai, b[i] = bi;
    a[now].cnt--;
    a[now].h += b[i].atk;
    b[i].h += a[now].atk;
  }
  return ans;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Node> a(n), b(m);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].h;
    a[i].atk = a[i].h;
  }
  for (int i = 0; i < m; i++) {
    std::cin >> b[i].h;
    b[i].atk = b[i].h;
  }
  std::array<double, 3> ans = {0, 0, 0};
  if (n > m) {
    ans = work(a, b);
  } else if (n < m) {
    ans = work(b, a);
    std::swap(ans[0], ans[1]);
  } else {
    auto aans = work(a, b), bans = work(b, a);
    ans[0] = (aans[0] + bans[1]) / 2.0;
    ans[1] = (aans[1] + bans[0]) / 2.0;
    ans[2] = (aans[2] + bans[2]) / 2.0;
  }
  std::cout << std::fixed << std::setprecision(20) << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
