#include <bits/stdc++.h>
using namespace std;

bitset<1000001> is_prime;
int primes[47001], primesum = 0, lim;

bool check(int n) {
  if (n <= lim) return is_prime[n];
  for (int i = 0; i < primesum; i++) {
    if (!(n % primes[i]))
      return false;
  }
  return true;
}

int main() {
  auto start = chrono::system_clock::now();
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int l, r;
  cin >> l >> r;
  is_prime.set();
  is_prime.reset(1);
  lim = ceil(sqrt(r));
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      primes[primesum++] = i;
    }
    for (int j = 0; j < primesum; j++) {
      if (1ll * i * primes[j] > lim) break;
      is_prime[i * primes[j]] = false;
      if (!(i % primes[j])) break;
    }
  }
  // auto end = chrono::system_clock::now();
  int ans = 0;
  for (int i = l; i < r; i++)
    if (check(i))
  //     cout << i << ' ';
  // if (check(r)) cout << r;
      ++ans;
  cout << ans + check(r);
  return 0;
}