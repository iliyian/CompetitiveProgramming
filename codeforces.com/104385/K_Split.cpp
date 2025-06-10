#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 7;
ll a[N], pre[N];
void solve(){
  ll n;
  cin >> n;
  for(int i = 1; i <= n; i++)cin >> a[i];
  ll m;
  cin >> m;
  ll ans = a[1] - a[n];
  vector<ll> v;
  for(int i = 2;i <= n; i++)v.push_back(a[i - 1] - a[i]);
  sort(v.begin(),v.end(),[&](ll p, ll q){return p > q;});

  for(int i = 1;i < n; i++)
    pre[i] = pre[i - 1] + v[i - 1];

  for(int i = 1; i <= m; i++){
    ll cmd, x;
    cin >> cmd >> x;
    if(cmd == 1){
      cout << ans - pre[x - 1] << "\n";
    }

  }
}
int main(){
  std::cin.tie(nullptr)->sync_with_stdio(false);
  solve();
  return 0;
}