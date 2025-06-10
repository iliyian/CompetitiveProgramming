#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
  int a1, a2, a3, a4, a5;
  std::cin >> a1 >> a2 >> a3 >> a4 >> a5;
  int ans = 0, cc;
  ans += a3 / 2;
  a3 %= 2;
  cc = min(a2, a4);
  ans += cc;
  a2 -= cc;
  a4 -= cc;
  cc = min(a1, a5);
  ans += cc;
  a1 -= cc;
  a5 -= cc;
  // cout << ans <<" ";
  if(a1 == 0 && a2 == 0){
    int cnt = min(a3, a5);
    int res = 0;
    ans += cnt;
    a3 -= cnt;
    a5 -= cnt;
    cnt = min(a4, a5);
    ans += cnt;
    a4 -= cnt;
    a5 -= cnt;
    cnt = a5 / 2;
    ans += cnt;
    a5 %= 2;
    res += a5;
    cnt = (res + a3 + a4) / 3;
    ans = ans + cnt;
  }
  else if(a1 == 0 && a4 == 0){
    int cnt = min(a2, a5);
    int res = 0;

    ans += cnt;
    a2 -= cnt;
    a5 -= cnt;
    cnt = min(a3, a5);
    ans += cnt;
    a3 -= cnt;
    a5 -= cnt;
    cnt = a5 / 2;
    ans += cnt;
    a5 %= 2;
    res += a5;

    if(a3 && a2 >= 2 || a3 && a2 && res){
      ans++;
      a3 = 0;
      if(!res)a2 -= 2;
      else a2--;
    }
    ans = ans + a2 / 3;
  }
  else if(a2 == 0 && a5 == 0){
    int cnt = min(a4, a1 / 2);
    int res = 0;

    ans += cnt;
    a4 -= cnt;
    a1 -= cnt * 2;


    if(a4 && a3 && a1){
      ans ++;
      a3--;
      a1--;
      a4--;
    }
    if(a4){
      cnt = (a4 + a1 + a3) / 3;
      ans += cnt;
    }
    else{
      if(a3 && a1 >= 3){
        ans++;
        a1-=3;
      }
      ans = ans + a1 / 6;
    }
  }
  else if(a4 == 0 && a5 == 0){
    int cnt = a1 + a2 * 2 + a3 * 3;
    ans = ans + cnt / 6;
  }
  cout << ans << "\n";
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