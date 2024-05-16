// date: 2024-05-15 12:03:09
// tag: 链表，贪心，位运算

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1), s(n + 1), x(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    x[i] = x[i - 1] ^ a[i];
  }
  vector<int> nxt(n + 1), prv(n + 1), cnt(n + 1);
  int p = 0;
  for (int i = 1; i <= n; i++) {
    prv[i] = p;
    if (a[i]) {
      p = i;
    }
  }
  p = n;
  for (int i = n; i >= 1; i--) {
    nxt[i] = p;
    if (a[i]) {
      p = i;
    }
  }
  auto check = [&](int l, int r) {
    return s[r] - s[l - 1] - (x[r] ^ x[l - 1]);
  };
  for (int _ = 1; _ <= q; _++) {
    int l, r;
    cin >> l >> r;
    int mx = check(l, r);
    if (mx == 0) {
      cout << l << ' ' << l << '\n';
      continue;
    }
    if (l < r && !a[l]) l = nxt[l];
    if (r > l && !a[r]) r = prv[r];
    // while (l < r && !a[l]) l++;  //这tmd是O(n)的艹
    // while (r > l && !a[r]) r--;
    int lpos = l;
    int ansl = l, ansr = r;
    for (int lcnt = 0; lcnt <= 30; lcnt++) {
      if (lpos > r || !lpos) {
        break;
      }

      int rpos = r;
      for (int rcnt = 0; rcnt + lcnt <= 30; rcnt++) {
        if (rpos < lpos || !rpos) {
          break;
        }
        
        if (check(lpos, rpos) == mx) {
          if (ansr - ansl > rpos - lpos) {
            ansr = rpos, ansl = lpos;
          }
        }

        rpos = prv[rpos];
      }

      lpos = nxt[lpos];
    }
    cout << ansl << ' ' << ansr << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C2.in", "r", stdin);
  freopen("C2.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}