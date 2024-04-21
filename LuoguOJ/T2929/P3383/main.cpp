// fuck it.

#include <bits/stdc++.h>
using namespace std;

bitset<100000001> is_prime;
int prime[10000001], cnt = 1;

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  is_prime.set();
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime[cnt++] = i;
      for (long long j = (long long)i * i; j <= n; j += i) is_prime[j] = false;
    }
  }
  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    cout << prime[k] << '\n';
  }
  return 0;
}