#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef pair<ll,ll> pll;
const int N = 1e5 + 7;
ll a[10], b[10], cnt[8] = {0, 1, 5, 10, 50, 100, 500, 1000};
ll mn = 1e18 + 7;
void dfs(ll x, ll ans){
  while(x > 0){
    ll res = x % 10;
    if(res == 0){
      for(int i = 3; cnt[i] <= x && i <= 7; i++){
        dfs((x - cnt[i]) / 10, ans + b[i]);
      }
      ans = ans + a[res];
    }
    else {
      ans = ans + a[res];
    }
    x /= 10;
  }
  mn = min(mn, ans);
}
void solve(){
  ll n;
  cin >> n;
  for(int i = 0; i <= 9; i++)cin >> a[i];
  for(int i = 1; i <= 7; i++)cin >> b[i];
  a[1] = min(a[1], b[1]);
  a[5] = min(a[5], b[2]);
  
  mn = 1e18 + 7;
  dfs(n, 0);
  cout << mn << "\n";
}
signed main(){
  ll T;
  cin >> T;
  while(T--)
    solve();
}