#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  std::vector<int> a(n + 1);
  std::vector<int> cnt1(n + 1), cnt0(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = (str[i] == '(' || str[i] == ')');
    // std::cout << a[i] << " \n"[i == n];
  }
  for (int i = 1; i <= n; i++) {
    cnt1[i] = cnt1[i - 1] + (a[i] == 1);
    cnt0[i] = cnt0[i - 1] + (a[i] == 0);
  }
  // a[0] = -1;
  // bool f = true;
  // bool l0 = false, l1 = false, r0 = false, r1 = false;
  // for(int i=1;i<=n/2;i++)
  // {
  //   if(a[i]==1)l1=1;
  //   if(a[i]==0)l0=1;
  // }
  // for(int i=n/2+1;i<=n;i++)
  // {
  //   if(a[i]==1)r1=1;
  //   if(a[i]==0)r0=1;
  // }
  // for (int i = 1; i <= n / 2; i++) 
  // {
  //   if (a[i] == a[i - 1]) 
  //   {
  //     if(a[i]==1)
  //     {
  //       if(r1)f=false;

  //     }
  //     else if(a[i]==0)
  //     {
  //       if(r0)f=false;
  //     }
  //     //
  //   }
  // }
  // for (int i = n / 2 + 1; i <= n - 1; i++) {
  //   if (a[i + 1] == a[i]) 
  //   {
  //     if(a[i]==1)
  //     {
  //       if(l1)f=false;
  //     }
  //     else if(a[i]==0)
  //     {
  //       if(l0)f=false;
  //     }
  //     //break;
  //   }
  // }
  // std::cout << (f ? "Yes" : "No") << '\n';
  
  // bool f = true, g = true;
  for (int i = 1; i <= n - 2; i++) {
    if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
      std::cout << "No\n";
      return;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] == a[i + 1]) {
      cnt++;
    }
  }
  if (cnt > 2) {
    std::cout << "No\n";
    return;
  }
  std::cout << "Yes\n";
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}