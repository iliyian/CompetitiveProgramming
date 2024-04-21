// date: 2023/12/15
// tag: 简单的找规律

#include <bits/stdc++.h>
#define N 1000005
using namespace std;

bitset<N> vis;
vector<int> pri;
int a[N];
map<int, int> cnt;

void solve() {
  int n;
  cin >> n;
  cnt.clear();
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int p : pri) {
      if (p * p > a[i]) break;
      while (a[i] % p == 0) {
        a[i] /= p;
        cnt[p]++;
      }
    }
    if (a[i] > 1) cnt[a[i]]++;
  }
  int val = 0;
  for (auto &[k, v] : cnt) {
    if (v % n) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  for (int i = 2; i <= N - 1; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p >= N) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }
  while (_--) solve();
}