// date: 2023/12/15
// tag: 关键在于发现积性，和避免溢出

#include <bits/stdc++.h>
#define N 1000005
#define int long long
using namespace std;

vector<int> pri;
bitset<N> vis;
map<int, int> cnt, rcnt;

int qpow(int a, int b, int mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * (a % mod) % mod;
    a = a * (a % mod) % mod;
    b >>= 1;
  }
  return ans % mod;
}

void solve() {
  int n, q;
  cin >> n >> q;
  int rawn = n;
  cnt.clear(), rcnt.clear();
  for (int p : pri) {
    if (p * p > n) break;
    while (n % p == 0) {
      rcnt[p]++;
      n /= p;
    }
  }
  if (n > 1) rcnt[n]++;
  cnt = rcnt;
  n = rawn;

  for (int i = 0; i < q; i++) {
    int k, x;
    cin >> k;
    if (k == 1) {
      cin >> x;
      for (int p : pri) {
        if (p * p > x) break;
        while (x % p == 0) {
          cnt[p]++;
          x /= p;
        }
      }
      if (x > 1) cnt[x]++;
      int dn = 1, cur = 1;
      bool f = false;
      for (auto &[k, v] : cnt)
        dn *= v + 1;
      for (auto &[k, v] : cnt) {
        cur = (cur * qpow(k, v, dn)) % dn;
        // 防溢出
        if (cur == 0) break;
      }
      if (cur % dn == 0) cout << "YES\n";
      else cout << "NO\n";
    } else {
      cnt = rcnt;
      n = rawn;
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);
  int _; cin >> _;
  for (int i = 2; i <= 1000002; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p >= 1000002) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }
  while (_--) solve();
}