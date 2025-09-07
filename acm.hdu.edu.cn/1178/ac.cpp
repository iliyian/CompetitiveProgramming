#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
const int N = 100005;
int Case, n, k, i, a[N], b[N], sa[N], sb[N];
ll v[N], q[N], lim;
inline bool checkleq() {
  if (lim > 0)
    return 0;
  int m = 1;
  q[1] = 0;
  for (int i = 1; i <= n; i++) {
    ll x = v[i];
    if (x < lim || x > 0)
      continue;
    if (x <= q[m]) {
      q[++m] = x;
      continue;
    }
    int l = 1, r = m - 1, fin = m;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (x > q[mid])
        r = (fin = mid) - 1;
      else
        l = mid + 1;
    }
    q[fin] = x;
  }
  return m > k;
}
inline bool checkle() {
  if (lim >= 0)
    return 0;
  int m = 1;
  q[1] = 0;
  for (int i = 1; i <= n; i++) {
    ll x = v[i];
    if (x < lim || x >= 0)
      continue;
    if (x < q[m]) {
      q[++m] = x;
      continue;
    }
    int l = 1, r = m - 1, fin = m;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (x >= q[mid])
        r = (fin = mid) - 1;
      else
        l = mid + 1;
    }
    q[fin] = x;
  }
  return m > k;
}
inline int dir(ll u, ll d) {
  for (int i = 1; i <= n; i++)
    v[i] = sb[i] * d - sa[i] * u;
  lim = v[n];
  if (checkleq()) {
    if (checkle())
      return -1;
    return 0;
  }
  return 1;
}
inline void solve() {
  ll lu = 0, ld = 1, ru = 1, rd = 1, mu, md;
  while (1) {
    mu = lu + ru;
    md = ld + rd;
    int ret = dir(mu, md);
    if (ret == 0) {
      cout << mu << "/" << md << "\n";
      break;
    }
    ll l = 1, r, fin, mid;
    if (ret > 0) { // turn right
      while (1) {
        r = l << 1;
        if (dir(lu + ru * r, ld + rd * r) > 0)
          l = r;
        else
          break;
      }
      fin = l++;
      r--;
      while (l <= r) {
        ll mid = (l + r) >> 1;
        if (dir(lu + ru * mid, ld + rd * mid) > 0)
          l = (fin = mid) + 1;
        else
          r = mid - 1;
      }
      lu += ru * fin, ld += rd * fin;
    } else { // turn left
      while (1) {
        r = l << 1;
        if (dir(ru + lu * r, rd + ld * r) < 0)
          l = r;
        else
          break;
      }
      fin = l++;
      r--;
      while (l <= r) {
        ll mid = (l + r) >> 1;
        if (dir(ru + lu * mid, rd + ld * mid) < 0)
          l = (fin = mid) + 1;
        else
          r = mid - 1;
      }
      ru += lu * fin, rd += ld * fin;
    }
  }
}
inline bool check1() {
  static int f[N], pre[N];
  f[0] = pre[0] = 0;
  for (int i = 1, j = 0; i <= n; i++) {
    if (a[i] != b[i])
      j = i;
    if (j)
      f[i] = pre[j - 1] + 1;
    else
      f[i] = -N;
    pre[i] = max(pre[i - 1], f[i]);
  }
  return f[n] >= k;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> Case;
  while (Case--) {
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      sa[i] = sa[i - 1] + a[i];
      sb[i] = sb[i - 1] + b[i];
    }
    if (sb[n] == 0) {
      cout << "0/1\n";
      continue;
    }
    if (!check1()) {
      cout << "1/1\n";
      continue;
    }
    solve();
  }
}