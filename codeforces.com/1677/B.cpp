// date: 2024-05-02 20:33:26
// tag: 模拟

#include <bits/stdc++.h>
#define int long long
#define N 1000000
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  int ccnt = 0;
  bitset<N + 1> visc;
  vector<int> rcnt(m);
  int lst = -n * m - 10;
  for (int i = 0; i < n * m; i++) {
    char ch;
    cin >> ch;
    if (ch == '1') {
      if (!visc[i % m]) {
        visc[i % m] = true;
        ccnt++;
      }
      lst = i;
    }
    rcnt[i % m] += i - lst < m;
    cout << rcnt[i % m] + ccnt << ' ';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}