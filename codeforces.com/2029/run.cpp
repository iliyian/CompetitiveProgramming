#include <bits/stdc++.h>
#define int long long


signed main(int argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  system(std::format("g++ {}.cpp -o {}.exe -g", argv[1], argv[1]).c_str());
  system(std::format("./{}.exe < {}.in > {}.out", argv[1], argv[1], argv[1]).c_str());
  return 0;
}