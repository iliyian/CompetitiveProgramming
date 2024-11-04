#include <bits/stdc++.h>
#include <iostream>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  int cnt = 0;
  std::string DLV = "DLV";
  bool split[100010];
  memset(split, 0, sizeof(split));
  int prv = 0;
  for (int i = 0; i < n; i++) 
  {
    //std::cout << i <<' ' <<cnt<<endl;
    if(i + 4 < n)
    {
      if(str.substr(i, 5) == "MMMCM" || str.substr(i, 5) == "CCCXC" || str.substr(i, 5) == "XXXIX")
      {
        split[i + 1] = 1;
        split[i + 4] = 1;
        i += 4;
        cnt+=2;
        continue;
      }
    }
    if(i + 3 < n)
    {
      if(str.substr(i, 4) == "MMCM" || str.substr(i, 4) == "CCXC" || str.substr(i, 4) == "XXIX")
      {
        split[i] = 1;
        split[i + 3] = 1;
        i += 3;
        cnt+=2;
        continue;
      }
    }
    if(i + 2 < n)
    {
      if(str.substr(i, 3) == "MCM" || str.substr(i, 3) == "CXC" || str.substr(i, 3) == "XIX" ||
         str.substr(i, 3) == "MMM" || str.substr(i, 3) == "CCC" || str.substr(i, 3) == "XXX" ||
         str.substr(i, 3) == "III" )
      {
        split[i + 2] = 1;
        i += 2;
        cnt++;
        continue;
      }
    }
    if(i + 1 < n)
    {
      if(str.substr(i, 2) == "MM" || str.substr(i, 2) == "CC" || str.substr(i, 2) == "XX" ||
         str.substr(i, 2) == "II" )
      {
        split[i + 1] = 1;
        i += 1;
        cnt++;
        continue;
      }
    }
    split[i] = 1;
    cnt++;
  }
  /*
    auto c = str.substr(i, 5);
    if (c == "MCM" || c == "CXC" || c == "XIX") {
      split[i + 2] = true;
      skip[i] = skip[i + 1] = skip[i + 2] = skip[std::max(0ll, i - 1)] = true;
      i += 2;
      split[std::max(0ll, i - 1)] = true;
    }



    if (c == "MCM" || c == "CXC" || c == "XIX") {
      split[i + 2] = true;
      skip[i] = skip[i + 1] = skip[i + 2] = skip[std::max(0ll, i - 1)] = true;
      i += 2;
      split[std::max(0ll, i - 1)] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (skip[i]) {
      prv = i + 1;
      continue;
    }
    if (i == n || str[i] != str[i - 1]) {
      if (DLV.find(str[i - 1]) != DLV.npos) {
        for (int j = prv; j <= i - 1; j++) {
          split[j] = true;
        }
      } else {
        for (int j = prv + 2; j <= i - 1; j += 3) {
          split[j] = true;
        }
        split[i - 1] = true;
      }
      prv = i;
    }
  }*/
  //int ans = std::count(split.begin() + 1, split.end(), 1);
  std::cout << cnt << '\n';
  for (int i = 0; i < n; i++) {
    std::cout << str[i];
    if (split[i]) std::cout << '\n';
  }
}

signed main() {
  freopen("H.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}