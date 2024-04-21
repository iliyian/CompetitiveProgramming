#include <bits/stdc++.h>
#define int long long
#define N 100005
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

int s1[N << 2], s2[N << 2], slen, tlen;
string s, t;

void pushup(int p, int which[]) {
  which[p] = which[lc] + which[rc];
}

void build(int l, int r, int p, int which[], string &str) {
  if (l == r) {
    which[p] = (str[l] == 'X' ? 2 : 1);
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc, which, str);
  build(mid + 1, r, rc, which, str);
  pushup(p, which);
}

int querysum(int l, int r, int s, int t, int p, int which[]) {
  if (l <= s && t <= r) return which[p];
  int mid = (s + t) / 2, ans = 0;
  if (l <= mid) ans += querysum(l, r, s, mid, lc, which);
  if (r > mid) ans += querysum(l, r, mid + 1, t, rc, which);
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int q;
  cin >> s >> t >> q;
  s = '#' + s, t = '#' + t;
  slen = s.size() - 1, tlen = t.size() - 1;

  build(1, slen, 1, s1, s);
  build(1, tlen, 1, s2, t);
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int sm1 = querysum(a, b, 1, slen, 1, s1);
    int sm2 = querysum(c, d, 1, tlen, 1, s2);
    if (abs(sm1 - sm2) % 3 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}