// #include <bits/stdc++.h>
// using namespace std;
// #define PB push_back
// #define MP make_pair
// #define fst first
// #define scd second

// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// using vi = vector<int>;
// using vl = vector<ll>;
// const ll INF = 1e18 + 7;
// const int N = 5e5 + 7;
// const int M = 5e8 + 7;
// const int modN = 998244353;
// mt19937_64 rng(time(0));


// void solve(){
//     ll n, k, m, a, b;
//     cin >> n >> k >> m >> a >> b;
//     if (k == 1 && n != m){
//         cout << "-1\n";
//         return;
//     }
//     else if(n % m == 0){
//         cout << "0\n";
//         return;
//     }
//     ll ans1 = 0, cur = n;
//     ll ans2 = INF;
//     vector<pll> v;
//     while(cur % m){
//         if (m > cur && m - cur < k)
//             ans2 = ans1 + a + b;
//         v.PB({cur, ans1});
//         cur /= k;
//         ans1 += b;
//     }
//     ll ans = min(ans1, ans2);
//     for(auto [x, y]: v) {
//         ll base = 1;
//         x %= m;
//         while(m - x >= base){
//             base *= k;
//             x = x * k;
//             x %= m;
//             y += a;
//         }
//         ans = min(ans, y);
//     }
//     cout << ans << "\n";
// }   
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ll T;
//     cin >> T;
//     while(T--)
//         solve();
//     return 0;
// }   

#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

int N = 1e2, M = 1e2;

void solve() {
  int n, k, m, a, b;
  n = rd() % N + 1;
  k = rd() % M + 1;
  m = rd() % M + 1;
  a = rd() % M + 1;
  b = rd() % M + 1;
  // std::cin >> n >> k >> m >> a >> b;
  std::cout << n << ' ' << k << ' ' << m << ' ' << a << ' ' << b << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1000;
  // std::cin >> t;
  std::cout << t << '\n';
  while (t--) {
    solve();
  }
  return 0;
}