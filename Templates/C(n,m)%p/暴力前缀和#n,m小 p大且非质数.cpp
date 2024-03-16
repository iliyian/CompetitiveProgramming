#include <bits/stdc++.h> //C(n,m)%p n,m??§³,p?? ??????????
// test:https://codeforces.com/contest/896/submission/227968276
using namespace std;
using ll = long long;
struct disolve1e18 {
  ll delt;
  vector<int> pris = {2, 3, 5, 7, 11, 13};
  ll mul(ll a, ll b, ll m) {
    ll res = 0;
    for (; b; (a <<= 1) %= m, b >>= 1)
      if (b & 1)
        (res += a) %= m;
    return res;
  }
  ll f(ll x, ll n) { return (mul(x, x, n) + delt) % n; } // ???????????
  ll _gcd(ll a, ll b) {
    if (a < b)
      swap(a, b);
    while (b)
      a %= b, swap(a, b);
    return a;
  }
  ll powm(ll bs, ll x, ll m) {
    ll res = 1;
    for (; x; x >>= 1, bs = mul(bs, bs, m))
      if (x & 1)
        res = mul(res, bs, m);
    return res;
  }
  bool miller_rabbin(ll n) { // is pri->true
    for (auto k : pris)
      if (n % k == 0)
        return (n == k);
    ll b = n - 1;
    int cnt = 0;
    while (!(b & 1))
      cnt++, b >>= 1;
    for (auto k : pris) {
      ll val = powm(k, b, n);
      for (int j = 0; j < cnt; j++) {
        ll v2 = mul(val, val, n);
        if (v2 == 1 && val != 1 && val != n - 1)
          return 0;
        val = v2;
      }
      if (val != 1)
        return 0;
    }
    return 1;
  }
  int find_factorplus(ll n) { // ??floyd???????
    for (ll a = 2, b = f(a, n); a != b; a = f(a, n), b = f(f(b, n), n)) {
      ll p = _gcd(abs(b - a), n);
      if (p > 1)
        return p;
    }
    return 0;
  }
  vector<ll> disolve(ll _n) {
    ll n, n2;
    n = _n;
    n2 = n;
    vector<ll> facs;
    if (n == 1)
      return facs;
    queue<ll> fds;
    fds.push(n);
    for (ll x; !fds.empty(); fds.pop()) {
      x = fds.front();
      if (x == 1)
        continue;
      while (!miller_rabbin(x))
        for (delt = 2;; delt++) {
          ll fac = find_factorplus(x);
          if (fac) {
            fds.push(fac);
            x /= fac;
            break;
          }
        }
      if (x > 1)
        facs.push_back(x);
    }
    sort(facs.begin(), facs.end());
    return facs;
  }
} mil;
struct BruteC { // C(n,m)%p n,m 1e5,p 1e9 ?????????? precal?????¦¶n,m/???p
                // //O(n*prid(p))
  ll mod, phi;
  int siz;
  vector<ll> facs;
  vector<vector<ll>> mul;
  ll poww(ll bs, ll x) {
    ll res = 1;
    for (bs %= mod; x; x >>= 1, (bs *= bs) %= mod)
      if (x & 1)
        (res *= bs) %= mod;
    return res;
  } // when p<1e9
  ll invv(ll bs) { return poww(bs, phi - 1); }
  vector<ll> era(vector<ll> &v) {
    vector<ll> v2;
    for (auto k : v)
      if (v2.empty() || v2.back() != k)
        v2.push_back(k);
    return v2;
  }
  void precal(ll _mod, int N) { // P:
    mod = _mod;
    facs = mil.disolve(mod);
    facs = era(facs);
    siz = facs.size();
    phi = mod;
    for (auto k : facs)
      phi = phi / k * (k - 1);
    vector<ll> bas(siz + 1, 0);
    bas[0] = 1;
    mul.resize(N + 1, bas);
    for (int i = 1; i <= N; i++) {
      int x = i;
      mul[i] = mul[i - 1];
      for (int j = 1; j <= siz; j++)
        while (x % facs[j - 1] == 0)
          x /= facs[j - 1], mul[i][j]++;
      (mul[i][0] *= x) %= mod;
    }
  }
  ll C(ll n, ll m) {
    if (n < m)
      return 0;
    ll res = mul[n][0] * invv(mul[m][0]) % mod * invv(mul[n - m][0]) % mod;
    for (int i = 1; i <= siz; i++)
      (res *= poww(facs[i - 1], mul[n][i] - mul[m][i] - mul[n - m][i])) %= mod;
    return res;
  }
} Bruc;
int main() {
  Bruc.precal(1e9, 1e5);
  cout << Bruc.C(4, 2) << '\n';
}
