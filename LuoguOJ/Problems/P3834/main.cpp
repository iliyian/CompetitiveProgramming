// date: 2024-02-29 13:24:52
// tag: wa#01: query的l和r也就是1和len和存储离散化数据的数组的索引对不上，后者0开始

#include <bits/stdc++.h>
#define N 200005
using namespace std;

int cnt = 0;
int ls[N << 5], rs[N << 5], rt[N << 5], sum[N << 5];

int build(int l, int r) {
  int root = ++cnt;
  if (l == r) return cnt;
  int mid = l + (r - l >> 1);
  ls[root] = build(l, mid);
  rs[root] = build(mid + 1, r);
  return root;
}

int update(int k, int l, int r, int p) {
  int root = ++cnt;
  ls[root] = ls[p], rs[root] = rs[p], sum[root] = sum[p] + 1;
  if (l == r) return root;
  int mid = l + (r - l >> 1);
  if (k <= mid)
    ls[root] = update(k, l, mid, ls[root]);
  else
    rs[root] = update(k, mid + 1, r, rs[root]);
  return root;
}

int query(int u, int v, int l, int r, int k) {
  int x = sum[ls[v]] - sum[ls[u]], mid = l + (r - l >> 1);
  if (l == r) return l;
  if (k <= x)
    return query(ls[u], ls[v], l, mid, k);
  else
    return query(rs[u], rs[v], mid + 1, r, k - x);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), v = {0};
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  sort(v.begin() + 1, v.end());
  v.erase(unique(v.begin() + 1, v.end()), v.end());
  auto get = [&](const int &x) {
    return lower_bound(v.begin() + 1, v.end(), x) - v.begin();
  };
  int len = v.size();
  rt[0] = build(1, len);
  for (int i = 1; i <= n; i++) {
    rt[i] = update(get(a[i]), 1, len, rt[i - 1]);
  }
  for (int i = 1; i <= m; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << v[query(rt[l - 1], rt[r], 1, len, k)] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}