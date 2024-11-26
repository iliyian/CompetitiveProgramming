#include <bits/stdc++.h>
#define int long long

int exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a; 
  }
  int t = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return t;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  sum %= m;
  int A = n % m, B = (n + 1) * n / 2 % m, x, y;
  int g = std::gcd(A, B);
  exgcd(A / g, B / g, x, y);
  std::cout << g << ' ' << x << ' ' << y << ' ' << sum << ' ';
  
  for (int i = 0; i < n; i++) 
  {
    C = (i % m + m - sum % m) % m;
    
    /*int t = m - sum - i;
    t = (t % m + m) % m;
    if (t % g) continue;*/
    //std::cout << t << ' ' << i << '\n';
  }
}

signed main() {
  freopen("A.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}