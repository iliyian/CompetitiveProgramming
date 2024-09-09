#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
int cul1(int x) // 0--n-1包含x
{
  return (k + k + x) * (x + 1) / 2;
}
int cul2(int x) // 不包含x
{
  return (n - 1 - x) * (k + n - 1 + k + x + 1) / 2;
}
void solve() {
  // cout<<"-----------------------------------"<<endl;
  cin >> n >> k;
  int l = 0, r = n - 1;
  int ans = cul2(0) + k;
  // cout<<"ans"<<ans<<endl;
  while (l <= r) {
    int mid = (l + r) / 2;
    ans = min(ans, abs(cul1(mid) - cul2(mid)));
    if (cul1(mid) < cul2(mid)) // if(check(mid))
    {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  std::cout << ans << endl;
  // cout << min(abs(cul1(l) - cul2(l)), abs(cul1(r) - cul2(r))) << endl;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int _;
  //_=1;
  cin >> _; // scanf("%d",&_);
  while (_--)
    solve();
  return 0;
}
