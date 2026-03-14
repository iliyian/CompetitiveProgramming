#include <bits/stdc++.h>
#include <cassert>

const int N = 2e5 * 32 + 5;
const int M = 30;

int tot;
int rt[N];

struct node {
  int ch[2];
  int sum;
} tr[N];

void insert(int &p, int t, const int x) {
  tr[++tot] = tr[p];
  p = tot;
  ++tr[p].sum;
  if (t < 0) return; 
  int v = (x >> t) & 1;
  insert(tr[p].ch[v], t - 1, x);
}

int query(int lp, int rp, int x) {
  int res = 0;
  for (int k = 30; k >= 0; k--) {
    int qw = ((x >> k) & 1) ^ 1;
    if (tr[tr[rp].ch[qw]].sum - tr[tr[lp].ch[qw]].sum > 0) {
      res |= (1 << k);
      if (rp != 0) rp = tr[rp].ch[qw];
      if (lp != 0) lp = tr[lp].ch[qw];
    } else {
      if (rp != 0) rp = tr[rp].ch[qw ^ 1];
      if (lp != 0) lp = tr[lp].ch[qw ^ 1];
    }
  }
  return res;
}

int n, q, a[N];

void solve() {
  tot = 0;
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    rt[i] = rt[i - 1];
    insert(rt[i], M, a[i]);
  }
  while (q--) {
    int l, r, x;
    std::cin >> l >> r >> x;
    int res;
    std::cout << (res = query(rt[l - 1], rt[r], x)) << '\n';

    // int blr = 0;
    // for (int i = l; i <= r; i++) blr = std::max(blr, a[i] ^ x);
    // assert(blr == res);
  }
}

 int main() {
   freopen("in.in", "r", stdin);
   freopen("out.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}