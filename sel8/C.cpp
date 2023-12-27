#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
#define N 100005
using namespace std;

int d[26][N << 2], n, q, occur[26];
string str;

void pushup(int p, int c) {
  d[c][p] = d[c][lc] + d[c][rc];
  // for (int i = 0; i < 26; i++)
    // d[i][p] = d[i][lc] + d[i][rc];
}

void build(int l, int r, int p) {
  if (l == r) {
    d[str[l] - 'a'][p] = 1;
    return;
  }
  int mid = l + (r - l >> 1);
  build(l, mid, lc);
  build(mid + 1, r, rc);

  for (int i = 0; i < 26; i++)
    pushup(p, i);
}

int query(int l, int r, int s, int t, int p, int c) {
  if (l <= s && t <= r) return d[c][p];
  int mid = s + (t - s >> 1), sum = 0;
  if (l <= mid) sum += query(l, r, s, mid, lc, c);
  if (r > mid) sum += query(l, r, mid + 1, t, rc, c);
  return sum;
}

void modify(int x, int s, int t, int p, char c, char o) {
  if (s == t && x == s) {
    d[o][p] = 0;
    d[c][p] = 1;
    return;
  }
  int mid = s + (t - s >> 1);
  if (x <= mid) modify(x, s, mid, lc, c, o);
  if (x > mid) modify(x, mid + 1, t, rc, c, o);
  pushup(p, c);
  pushup(p, o);
}

void solve() {
  cin >> n >> str >> q;
  str = '#' + str;
  build(1, n, 1);
  for (int i = 1; i <= n; i++)
    occur[str[i] - 'a']++;
  for (int _ = 0; _ < q; _++) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      char c;
      cin >> x >> c;

      occur[str[x] - 'a']--, occur[c - 'a']++;
      char ori = str[x];
      str[x] = c;

      modify(x, 1, n, 1, c - 'a', ori - 'a');
    } else {
      int l, r;
      cin >> l >> r;

      bool f = true;
      for (int i = l; i < r; i++) {
        if (str[i] > str[i + 1]) {
          f = false;
          break;
        }
      }
      if (!f) {
        cout << "No\n";
        continue;
      }
      for (char i = str[l] + 1; i < str[r]; i++) {
        if (query(l, r, 1, n, 1, i - 'a') != occur[i - 'a']) {
          f = false; break;
        }
      }
      if (!f) {
        cout << "No\n";
        continue;
      }
      cout << "Yes\n";

    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}