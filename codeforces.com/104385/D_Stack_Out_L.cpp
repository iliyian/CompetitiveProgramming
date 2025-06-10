#include <bits/stdc++.h>
using namespace std;
#define int long long
const int modN = 998244353;
const int N = 6005;

std::vector<int> fac(N + 1), inv(N + 1), ifac(N + 1);

int C(int n, int m) {
  int ans = fac[n] * ifac[m] % modN * ifac[n - m] % modN;
  return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  if(n == 1 && k == 1){
    cout<<"1\n";
    return;
  }
  vector<vector<int>> dp(n + 1,vector<int>(n + 1, 0));
  vector<vector<int>> pre(n + 1,vector<int>(n + 1, 0));
  dp[0][0] = 1;
  pre[0][0] = pre[0][1] = 1;
  for(int i = 1;i <= n; i ++){
    for(int j = 0; j <= i;j ++){
      dp[i][j] = pre[i - 1][j];
      // cerr << dp[i][j] <<" ";
    }
    // cerr <<"\n"; 
    int l = 0, sum = 0;
    if(i == n)break;
    for(int j = 0; j <= i + 1;j++){
      if(j - k + 1 > l){
        sum -= dp[i][l];
        l++;
      }
      sum += dp[i][j];
      sum %= modN;
      sum = (sum + modN) % modN;
      pre[i][j] = sum;
    }
  }
  int ans = C(2 * n, n) * inv[n + 1];
  ans %= modN;
  ans -= dp[n][n];
  ans = (ans + modN) % modN;
  cout << ans << "\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  fac[0] = 1;
  inv[1] = 1;
  ifac[0] = 1;
  ifac[1] = 1;
  for (int i = 1; i <= N; i++) {
    fac[i] = fac[i - 1] * i % modN;
  }
  for (int i = 2; i <= N; i++) {
    inv[i] = (modN - modN / i) * inv[modN % i] % modN;
    ifac[i] = ifac[i - 1] * inv[i] % modN;
  }
  // std::cerr << C(132, 66) << '\n';

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}