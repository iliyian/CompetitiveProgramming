#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::map<int, int> mp, mp2, mpp, mp3;
  int prime = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    std::vector<int> fac;
    int t = a[i];
    for (int j = 2; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        fac.push_back(j);
        while (a[i] % j == 0) a[i] /= j;
      }
    }
    if (a[i] > 1) fac.push_back(a[i]);
    if (fac.size() == 1) {
      if (fac[0] * fac[0] == t) {
        mp2[fac[0]]++;
        ans += mp2[fac[0]] + mp[fac[0]];
      } else if (fac[0] == t) {
        ans += prime - mp[fac[0]] + mp2[fac[0]] + mp3[fac[0]];
        prime++;
        mp[fac[0]]++; 
      }
    } else if (fac.size() == 2) {
      if (fac[0] * fac[1] == t) {
        mpp[t]++;
        ans += mp[fac[0]] + mp[fac[1]] + mpp[t];
        mp3[fac[0]]++, mp3[fac[1]]++;
      }
    }
    // std::cerr << fac.size() << ' ' << ans << '\n';
  }
  std::cout << ans << '\n';
  // std::cerr << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}