#include <bits/stdc++.h>
#define maxn 4600000
#define ll long long
using namespace std;

int pri[maxn], phi[maxn], pricnt = 0;
ll sphi[maxn], p, n, inv;
bool notpri[maxn];
map<ll, ll> mp;
ll pw(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1)
      (ret *= a) %= p;
    (a *= a) %= p;
    b >>= 1;
  }
  return ret;
}
void init() {
  inv = pw(6, p - 2);
  phi[1] = 1;
  for (int i = 2; i < maxn; i++) {
    if (!notpri[i]) {
      pri[++pricnt] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= pricnt; j++) {
      if (i * pri[j] >= maxn)
        break;
      notpri[i * pri[j]] = true;
      if (i % pri[j] == 0) {
        phi[i * pri[j]] = phi[i] * pri[j];
        break;
      }
      phi[i * pri[j]] = phi[i] * (pri[j] - 1);
    }
  }
  for (int i = 1; i < maxn; i++)
    sphi[i] = (sphi[i - 1] + 1LL * i * i % p * phi[i] % p) % p;
}
ll s2(ll x) {
  x %= p;
  return x * (x + 1) % p * (2 * x + 1) % p * inv % p;
}
ll s3(ll x) {
  x %= p;
  return (x * (x + 1) / 2) % p * ((x * (x + 1) / 2) % p) % p;
}
ll calc(ll x) {
  if (x < maxn)
    return sphi[x];
  if (mp[x])
    return mp[x];
  ll pos, ret = s3(x);
  for (ll i = 2; i <= x; i = pos + 1) {
    pos = x / (x / i);
    (ret -= 1LL * (s2(pos) - s2(i - 1) + p) % p * calc(x / i) % p) %= p;
  }
  (ret += p) %= p;
  return mp[x] = ret;
}
ll solve() {
  ll pos, ret = 0;
  for (ll i = 1; i <= n; i = pos + 1) {
    pos = n / (n / i);
    (ret += 1LL * (calc(pos) - calc(i - 1) + p) % p * s3(n / i) % p) %= p;
  }
  (ret += p) %= p;
  return ret;
}
int main() {
  scanf("%lld%lld", &p, &n);
  init();
  printf("%lld\n", solve());
  return 0;
}