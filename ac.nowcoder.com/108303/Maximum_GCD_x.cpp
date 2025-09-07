#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
int n, a[N], ans1, ans2, ans3, s1[N], s2[N];
int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
void solve() {
  int flag = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    s1[i] = s2[i] = 0;
    cin >> a[i];
    if (a[i] != a[i - 1] && i > 1)
      flag = 0;
  }
  if (flag) {
    cout << 0 << endl;
    return;
  }
  ans1 = ans2 = ans3 = 0;
  for (int i = 2; i <= n; i++)
    ans1 = gcd(ans1, abs(a[i] - a[i - 1]));
  s1[1] = a[1];
  for (int i = 2; i <= n; i++)
    s1[i] = gcd(s1[i - 1], a[i]);
  s2[n] = a[n];
  for (int i = n - 1; i > 0; i--)
    s2[i] = gcd(s2[i + 1], a[i]);
  s1[0] = 0, s2[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    int x = gcd(s1[i - 1], s2[i + 1]);
    ans2 = max(ans2, x);
  }
  for (int i = 1; i < n; i++) {
    int x = gcd(s1[i - 1], s2[i + 2]);
    if (x == 0)
      continue;
    if (a[i] % x == a[i + 1] % x)
      ans3 = max(ans3, x);
  }
  if (n >= 3) {
    int x = gcd(a[1], a[n]);
    if (x > 0) {
      int r = a[2] % x;
      flag = 1;
      for (int i = 3; i < n; i++)
        if (a[i] % x != r) {
          flag = 0;
          break;
        }
      if (flag) {
        ans3 = max(ans3, x);
      }
    }
  }
  cout << max(ans1, max(ans2, ans3)) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--)
    solve();
  return 0;
}