#include <bits/stdc++.h>
#define int long long

std::pair<int, int> calc(std::string str) {
  int n = str.size();
  str = '#' + str;
  int c1 = 0, c0 = 0;
  std::vector<int> lcy(n + 1), rcy(n + 2), lcs(n + 2), rcs(n + 2), 
    lce(n + 1), rce(n + 2), lcn(n + 1), rco(n + 2), rcn(n + 1), lco(n + 1);
  for (int i = 1; i <= n; i++) {
    lcy[i] = lcy[i - 1];
    lce[i] = lce[i - 1];
    lcs[i] = lcs[i - 1];
    lcn[i] = lcn[i - 1];
    lco[i] = lco[i - 1];
    if (str[i] == 'N') lcn[i]++;
    if (str[i] == 'O') c0 += lcn[i], lco[i]++;
    if (str[i] == 'Y') lcy[i]++;
    if (str[i] == 'E') lce[i] += lcy[i];
    if (str[i] == 'S') c1 += lce[i], lcs[i]++;
  }
  return {c1, c0};
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    std::string str;
    std::cin >> str;
    std::string yesno = "YESNO";
    auto [c1, c0] = calc(str);
    std::cout << c1 << ' ' << c0 << '\n';
    for (int i = 0; i < str.size(); i++) {
      auto t = str[i];
      for (int j = 0; j < 5; j++) {
        str[i] = yesno[j];
        auto ans = calc(str);
        str[i] = t;

        if (c1 > c0 && ans.first < ans.second) {
          std::cout << "O BUDUI BUDUI\n";
          std::cerr << i + 1 << ' ' << str[i] << ' ' << yesno[j] << '\n';
          std::cerr << ans.first << ' ' << ans.second << '\n';
          return 0;
        }
        if (c1 < c0 && ans.first > ans.second) {
          std::cout << "O DUI DE\n";
          std::cerr << i + 1 << ' ' << str[i] << ' ' << yesno[j] << '\n';
          std::cerr << ans.first << ' ' << ans.second << '\n';
          return 0;
        }
      }
      
    }
    
    if (c1 > c0) {
      std::cout << "DUI DE\n";
    } else {
      std::cout << "BUDUI BUDUI\n";
    }
  }
  return 0;
}