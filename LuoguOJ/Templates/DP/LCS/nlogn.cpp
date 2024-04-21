#include <bits/stdc++.h>
#define N 100001
using namespace std;

int a[N], b[N], c[N], pos[N], ans[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i], pos[a[i]] = i;
  for (int i = 0; i < n; i++)
    cin >> b[i], c[i] = pos[b[i]];
  int len = 0;
  ans[0] = -0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    if (ans[len] < c[i]) ans[++len] = c[i];
    else *lower_bound(ans, ans + len, c[i]) = c[i];
  }
  cout << len;
  // for (int i = 1; i <= len; i++)
  //   cout << a[ans[i]] << ' ';
  return 0;
}