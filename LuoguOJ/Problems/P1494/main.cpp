// date: 2024-03-18 20:43:57
// tag: 莫队模板，奇偶化排序

#include <bits/stdc++.h>
#define int long long
using namespace std;

int maxn = -1;
struct Node {
  int l, r, id;
  bool operator < (const Node &b) const {
    if (l / maxn != b.l / maxn) return l < b.l;
    return l / maxn % 2 ? r < b.r : b.r < r;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, q;
  cin >> n >> q;
  vector<int> c(n + 1);
  maxn = sqrt(n);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  vector<Node> ask(q);
  vector<int> ans1(q), ans2(q);
  for (int t = 0; t < q; t++) {
    cin >> ask[t].l >> ask[t].r;
    ask[t].id = t;
  }
  int sum = 0;
  vector<int> cnt(n + 1);
  auto add = [&](int x) {
    sum -= cnt[x] * cnt[x];
    cnt[x]++;
    sum += cnt[x] * cnt[x];
  };
  auto del = [&](int x) {
    sum -= cnt[x] * cnt[x];
    cnt[x]--;
    sum += cnt[x] * cnt[x];
  };
  sort(ask.begin(), ask.end());
  for (int i = 0, l = 1, r = 0; i < q; i++) {
    if (ask[i].l == ask[i].r) {
      ans1[ask[i].id] = 0, ans2[ask[i].id] = 1;
      continue;
    }
    while (l > ask[i].l) add(c[--l]);
    while (r < ask[i].r) add(c[++r]);
    while (l < ask[i].l) del(c[l++]);
    while (r > ask[i].r) del(c[r--]);
    ans1[ask[i].id] = sum - (r - l + 1);
    ans2[ask[i].id] = (r - l + 1) * (r - l);
  }

  for (int i = 0; i < q; i++) {
    if (ans1[i] == 0) {
      cout << "0/1" << '\n';
    } else {
      int g = gcd(ans1[i], ans2[i]);
      cout << ans1[i] / g << '/' << ans2[i] / g << '\n';
    }
  }

  return 0;
}