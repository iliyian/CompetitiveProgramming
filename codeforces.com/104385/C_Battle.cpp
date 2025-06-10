#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, p;
  std::cin >> n >> p;
  std::vector<int> a(n + 1);
  std::set<int> s;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if(p % 2)a[i] %= 2;
    else{
      int res = a[i] % (p + 1);
      if(res == p)a[i] = 2;
      else a[i] = res % 2;
    }
    ans ^= a[i];
  }
  // std::cerr<<ans<<"\n";
  if(ans == 0)std::cout<<"BAD\n";
  else std::cout<<"GOOD\n";
}

std::map<std::array<int, 2>, int> sg;
int get(int m, int p) {
  if (m == 0) return 0;
  if (sg.count({m, p})) return sg[{m, p}];
  std::set<int> s;
  s.insert(get(m - 1, p));
  for (int i = p; i <= m; i *= p) {
    s.insert(get(m - i, p));
  }
  for (int i = 0;; i++) {
    if (!s.count(i)) {
      return sg[{m, p}] = i;
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

//   int np = 10, nm = 50;
//   for (int p = 2; p <= np; p++) {
//     for (int m = 1; m <= nm; m++) {
//       std::cout << p << ' ' << m << ' ' << get(m, p) << '\n';
//     }
//   }
// 
//   return 0;
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}