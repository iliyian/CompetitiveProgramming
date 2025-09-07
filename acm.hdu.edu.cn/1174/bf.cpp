#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, l[400005], r[400005], ans = 0;
int solve() {
  ans = 0;
  map<string, bool> a;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> l[i] >> r[i];
  for (int i = 0; i <= 301; i++) {
    string st = "";
    for (int j = 1; j <= n; j++)
      if (i >= l[j] && i <= r[j])
        st += '1';
      else
        st += '0';
    if (a[st] == 0)
      a[st] = 1, ans++;
  }
  cout << ans << endl;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}