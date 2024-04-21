#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100001], b[100001];

void exgcd(int an, int bn, int &x, int &y) {
  if (bn == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(bn, an % bn, y, x);
  y -= an / bn * x;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  int muln = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    muln *= a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int mi = muln / a[i], x, y;
    exgcd(mi, a[i], x, y);
    x = (x % a[i] + a[i]) % a[i];
    ans += b[i] % muln * x % muln * mi % muln;
    ans %= muln;
  }
  cout << (ans % muln + muln) % muln;
  return 0;
}