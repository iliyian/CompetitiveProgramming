#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b, n, S;
  std::cin >> a >> b >> n >> S;
  if (a * n + b < S) {
    std::cout << "NO\n";
    return;
  }
  int t = std::min(S / n, a);
  if (b + n * t < S) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
}

signed main() {
  freopen("D.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}