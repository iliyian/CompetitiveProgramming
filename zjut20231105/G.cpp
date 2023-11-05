#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

int cnt[150], sum[150];

void pushup(int p) {
  sum[p] = (sum[p << 1] % mod + sum[p << 1 | 1] % mod) % mod;
}

void update(int s, int t, int p, int i) {
  if (s == t && s == i) {
    sum[p]++;
    sum[p] %= mod;
    return;
  }
  int mid = s + (t - s >> 1);
  if (mid >= i) update(s, mid, p << 1, i);
  if (mid < i) update(mid + 1, t, p << 1 | 1, i);
  pushup(p);
}

int query(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) {
    return sum[p];
  }
  int mid = s + (t - s >> 1), ans = 0;
  if (l <= mid) ans += query(l, r, s, mid, p << 1);
  if (r > mid) ans += query(l, r, mid + 1, t, p << 1 | 1);
  return ans;
}

void exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("G.in", "r", stdin);
  string str;
  cin >> str;
  int n;
  cin >> n;

  str = '#' + str;
  int x, y;
  int len = 26;

  exgcd(2, mod, x, y);
  x = (x % mod + mod) % mod;
  int ans = 0, cnt;
  if (n > 1)
    cnt = (n + 1) % mod * x % mod * (n % mod) % mod;
  else cnt = 1;

  for (int i = 1; i < str.size(); i++) {
    update(1, len, 1, str[i] - 'a' + 1);
    if (i > 1) {
      int t = query(str[i] - 'a' + 2, len, 1, len, 1);
      ans += t % mod * cnt % mod;
      ans %= mod;
    }
  }

  memset(sum, 0, sizeof(sum));
  if (n > 1) {
    n--;
    cnt = (n + 1) % mod * x % mod * (n % mod) % mod;
    for (int i = str.size() - 1; i >= 1; i--) {
      update(1, len, 1, str[i] - 'a' + 1);
      if (i < str.size() - 1) {
        int t = query(str[i] - 'a' + 2, len, 1, len, 1);
        ans += t % mod * cnt % mod;
        ans %= mod;
      }
    }
  }
  cout << ans;
  return 0;
}