#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef pair<ll,ll> pll;
const int N = 1e5 + 7;
ll a[N],b[N];
void solve(){
  ll n;
  cin >> n;
  vector<pll> p, q;
  for(int i = 1;i <= n;i++){
    ll x, y, c, d;
    cin >> x >> y >> c >> d;
    if(c && d){
      if(x < y)
        p.PB({x, i});
      else
        q.PB({y, i});
    }
    else if(c){
      p.PB({x, i});
    }
    else if(d){
      q.PB({y, i});
    }
  }
  sort(p.begin(),p.end());
  sort(q.begin(),q.end());
  cout << p.size()<<" ";
  for(auto x :p) 
    cout << x.second << " ";
  cout << "\n";
  cout<<q.size()<<" ";
  for(auto x :q){
    cout << x.second << " ";
  }
  cout << "\n";
}
signed main(){
  solve();
}