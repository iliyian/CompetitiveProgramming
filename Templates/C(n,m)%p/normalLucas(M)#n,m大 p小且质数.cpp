// normalLucas#n,m�� pС������
// test:https://vjudge.csgrandeur.cn/contest/587114#problem/C
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 1000003;
struct NormLucas {
  ll poww(ll bs, ll x) {
    ll res = 1;
    for (bs %= M; x; x >>= 1, (bs *= bs) %= M)
      if (x & 1)
        (res *= bs) %= M;
    return res;
  }
  ll invv(ll bs) { return poww(bs, M - 2); }
  vector<ll> mul, inv;
  void precal(int P) {
    mul.resize(P + 1);
    mul[0] = 1;
    for (int i = 1; i <= P; i++)
      mul[i] = mul[i - 1] * i % M;
    inv.resize(P + 1);
    inv[P] = invv(mul[P]);
    for (int i = P; i; i--)
      inv[i - 1] = inv[i] * i % M;
  }
  ll C2(int n, int m) {
    return (n < m) ? 0 : mul[n] * inv[m] % M * inv[n - m] % M;
  }
  ll C(int n, int m) {
    ll res = 1;
    while (n || m)
      res *= C2(n % M, m % M), n /= M, m /= M;
    return res;
  }
} NLuca;
void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  cout << (NLuca.C(n + r - l + 1, n) - 1 + M) % M << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  NLuca.precal(M - 1);
  int t = 1;
  cin >> t;
  while (t--)
    solve(); /**/
}