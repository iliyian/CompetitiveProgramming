#include <bits/stdc++.h>
#define N 200001
using namespace std;

int a[N], sum[N];

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

void solve() {
  int n;
  cin >> n;
  int prev, cur;
  cin >> prev;
  int mn = min(0, prev), sum = prev, ans = prev;
  for (int i = 1; i < n; i++) {
    cin >> cur;
    if (abs(cur % 2) == abs(prev % 2)) {
      mn = 0, sum = 0;
    }
    sum += cur;
    ans = max(ans, sum - mn);
    mn = min(mn, sum);
    prev = cur;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}