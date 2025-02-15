#include <bits/stdc++.h>
#include <random>
using namespace std;
std::mt19937_64 rd(std::random_device{}());

constexpr int N = 1e5, M = 5e5;
#define int long long

void solve(){
    int n = rd() % N + 1, m = rd() % (M + 1), q = rd() % M + 1, V = rd() % (1ll << 60);
    // cin >> n >> m >> q >> 
    std::cout << n << ' ' << m << ' ' << q << ' ' << V << '\n';

    for (int i = 1; i <= m;i++){
      int u = rd() % n + 1, v = rd() % n + 1;
      int w = rd() % (1ll << 60);
      while (u == v) {
        u = rd() % n + 1, v = rd() % n + 1;
      }
      std::cout << u << ' ' << v << ' ' << w << '\n';
    }
    for (int i = 1; i <= q; i++) {
      int u = rd() % n + 1, v = rd() % n + 1;
      while (u == v) {
        u = rd() % n + 1, v = rd() % n + 1;
      }
      std::cout << u << ' ' << v << '\n';
    }
}   
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}   