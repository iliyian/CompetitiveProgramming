#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::ofstream dataout("d.in");

  std::mt19937 rd(std::random_device{}());

  int n = 1e3, q = 1e3, w = 26;
  dataout << n << '\n';
  std::string s(n, '0');
  for (int i = 0; i < n; i++) {
    s[i] = char(rd() % w + 'a');
  }
  dataout << s << '\n';
  dataout << q << '\n';
  while (q--) {
    int op = rd() % 2 + 1;
    dataout << op << ' ';
    if (op == 1) {
      int x = rd() % n + 1;
      char c = rd() % w + 'a';
      dataout << x << ' ' << c << '\n';
    } else {
      int l = rd() % n + 1, r = rd() % n + 1;
      if (l > r) std::swap(l, r);
      dataout << l << ' ' << r << '\n';
      auto t = s.substr(l - 1, r - l + 1);
      auto ss = s;
      std::ranges::sort(ss);
      dataout << (ss.find(t) != ss.npos ? "Yes" : "No") << '\n';
    }
  }

  return 0;
}