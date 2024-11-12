#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100010], l[100010], t[100010], ans, sum, x;

void solve() {
  int n, m;
  std::cin >> n >> m;
  ans = sum = 0, x;
  for(int i = 1; i <= n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  for(int i = 1; i <= m; i++)
  {
    cin >> l[i] >> t[i];
    l[i] -= l[i - 1];
  }
  l[m + 1] = sum + 1;
  x = 0;
  for(int i = 1; i <= m+1; i++)
  {
    if(l[i] > sum) {ans += sum;break;}
    sum -= l[i];
    ans += l[i];
    if(x + l[i] >= a[t[i]]) {x = x + l[i] - a[t[i]];sum += a[t[i]];}
    else {sum += x + l[i];x = 0;}
  }
  cout << ans << endl;
}

signed main() 
{
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t=1;
  std::cin >> t;
  while (t--) 
  {
    solve();
  }
  return 0;
}