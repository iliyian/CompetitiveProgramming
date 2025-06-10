#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 7;
int a[N];
void solve() {
  int n;
  cin >> n;
  set<int> s;
  for(int i = 1;i <= n; i++)cin >> a[i];
  int mex = 1;
  s.insert(0);
  s.insert(n + 1);
  int ans = 0;
  int cur = 1;
  for(int i = 1; i <= n; i ++){
    auto l = s.find(a[i] - 1),r=s.find(a[i] + 1);
    if(l != s.end() && r != s.end()){
      ans ++;
      cur --;
    }
    else if(l == s.end() && r == s.end()){
      cur ++;
    }
    while(s.find(mex) != s.end())mex++;
    if(mex == a[i])ans += cur;
    s.insert((a[i]));
    cerr << cur <<" ";
  }
  cout << ans << "\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}