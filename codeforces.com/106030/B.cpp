#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
  long double ppmax,a,b,c,d,e,f;
  cin >> ppmax >> a >> b >> c >> d >> e >> f;
  long double acc = (300 * a + 300 * b + 200 * c + 100 * d + 50 * e) * 100 / (300 * (a+b+c+d+e+f));
  std::cout << std::fixed << std::setprecision(2) << acc << '%' << ' ';
  // printf("%.2l%% ",acc*100);
  long double pp = (320*a+300*b+200*c+100*d+50*e) * 5 * ppmax / (320*(a+b+c+d+e+f)) - 0.8 * 5 * ppmax;
  if(pp < 0) pp = 0;
  // pp = pp*5*ppmax;
  // std::cerr << std::fixed << std::setprecision(20) << pp << '\n';
  // int ans = pp + 0.5;
  std::cout << (int)std::round(pp) << '\n';
  // printf("%lld\n", ans);
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