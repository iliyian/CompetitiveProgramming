// date: 2023/11/20
// tag: 莫队模板

#include <bits/stdc++.h>
#define N 50200
#define int long long
using namespace std;

int maxn;

struct Query {
  int l, r, id;
  bool operator < (const Query &b) const {
    // 不分块似乎理论上也可以
    // if (l == b.l) return r < b.r;
    // return l < b.l;
    // 直接比l的话1.7s，这样0.9s
    if (l / maxn != b.l / maxn) return l < b.l;
    return ((l / maxn) & 1) ? r < b.r : l < b.l;
  }
} queries[N];

int a[N], cnt[N], sonsum = 0;
pair<int, int> ans[N];

void add(int i) {
  sonsum += cnt[i];
  cnt[i]++;
}

void del(int i) {
  cnt[i]--;
  sonsum -= cnt[i];
}

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  maxn = sqrt(n);
  // maxn = 500;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++) {
    cin >> queries[i].l >> queries[i].r;
    queries[i].id = i;
  }
  sort(queries, queries + m);
  for (int i = 0, l = 1, r = 0; i < m; i++) {
    Query &query = queries[i];
    if (query.l == query.r) {
      ans[query.id] = {0, 1};
      continue;
    }
    while (l > query.l) add(a[--l]);
    while (r < query.r) add(a[++r]);
    while (l < query.l) del(a[l++]);
    while (r > query.r) del(a[r--]);
    ans[query.id] = {sonsum, (r - l + 1) * (r - l) / 2};
  }
  for (int i = 0; i < m; i++) {
    if (ans[i].first) {
      int g = gcd(ans[i].first, ans[i].second);
      ans[i].first /= g, ans[i].second /= g;
    } else ans[i].second = 1;
    cout << ans[i].first << '/' << ans[i].second << '\n';
  }
  return 0;
}