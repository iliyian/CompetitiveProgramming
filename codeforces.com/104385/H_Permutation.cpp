#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int N = 2e6 + 7;
const int NN = 2.5e5;
ll a[N];
void solve(){
  ll n;
  cin >> n;
  for(int i = 1;i <= n;i++)cin >> a[i];

  ll mx = 0, cnt = 0;
  vector<ll> v;
  for(int i = 1;i <= n; i++){
    if(a[i] > mx){
      v.push_back(cnt);
      cnt = 1;
      mx = a[i];
    }
    else {
      cnt++;
    }
  }
  v.push_back(cnt);
  for(auto x: v)cerr<<x<<" ";
  std::cerr <<'\n';
  std::bitset<NN + 1> f;
  f[0] = 1;
  std::vector<int> c(n + 1);
  for (auto x : v) {
    c[x]++;
  }
  std::vector<int> vv;
  for (int i = 0; i <= n; i++) {
    if (c[i]) {
      int k = 1;
      while (c[i] > k) {
        vv.push_back(k * i);
        c[i] -= k;
        k *= 2;
      }
      vv.push_back(c[i] * i);
    }
  }
  for (auto x : vv) {
    f |= f << x;
    // std::cerr << x << ' ';
    // for (int i = 0; i <= n / 2; i++) {
    //   std::cout << f[i] << ' ';
    // }
    // std::cout << '\n';
    if (f[n / 2]) {
      std::cout << "Yes\n";
      // std::cerr << '\n';
      return;
    }
  }
  // std::cerr << '\n';
  std::cout << "No\n";
}
int main(){
  std::cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}