#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
  int n, m, ans;
  std::cin >> n >> m;
  ans = m / n;
  if((((m / n) * n + 1) ^ (n - 1)) <= m)ans++;
  if((((m / n + 1) * n + 1) ^ (n - 1)) <= m)ans++;
  cout << ans <<endl;
  //for(int i = 0; i <= m; i++)
  //if((i ^ (n - 1)) % n == 1)cout << i<< ' ';
  }

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}