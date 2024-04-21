#include <bits/stdc++.h>
using namespace std;

int a[2000002], n, k, b1[35], b2[35], c[2000002];

void solve(int v) {
  int len1 = 0, len2 = 0;
  memset(b1, 0, sizeof(b1));
  memset(b2, 0, sizeof(b2));
  while (v)
    b1[len1++] = v & 1, v >>= 1;
  int t = k;
  while (t)
    b2[len2++] = t & 1, t >>= 1;
  int len = max(len1, len2);
  int res = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (b2[i] == 0) {
      res = (res << 1) + b1[i];
    } else {
      // if the same, inc a range of value's cnt
      // all x bwtween there
      c[(res * 2 + b1[i]) << i]++,
      c[(res * 2 + b1[i] + 1) << i]--;
      
      res = res * 2 + b1[i] ^ 1;
    }
  }
  c[res]++, c[res + 1]--;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> k;
  int maxn = -1;
  for (int i = 0; i < n; i++)
    cin >> a[i], maxn = max(maxn, a[i]), solve(a[i]);
  for (int i = 1; i <= maxn * 2; i++) {
    c[i] += c[i - 1];
  }
  int ans = -1;
  for (int i = 1; i <= maxn * 2; i++)
    ans = max(ans, c[i]);
  cout << ans;
  return 0;
}