#include<bits./stdc++.h>
#define int long long
using namespace std;
int get(int x)
{
  return (x + 1) * x / 2;
}
void solve()
{
  int n,k;
  cin >> n >> k;
  int fn = n;
  int ans = 0;
  while(n >= k)
  {
    ans += (get(n) - get(fn - n)); 
    n = n - n / k;
  }
  ans += (get(n) - get(fn - n)); 
  cout << ans << '\n';
}
signed main(){
  int T = 1;
  cin >> T;
  while(T--) solve();
  return 0;
}