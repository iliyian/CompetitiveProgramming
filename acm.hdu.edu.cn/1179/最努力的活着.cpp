#include <bits/stdc++.h>
#define int long long

void write(__int128 x) {
  if (x < 10) {
    putchar(x + '0');
    return;
  }
  write(x / 10);
  putchar(x % 10 + '0');
}

void solve() {
  int n, w;
  auto get1 = [&](__int128 x) {
    // assert(x >= 0);
    return x * (x + 1) / 2;
  };
  auto get2 = [&](__int128 x) {
    return x * (x + 1) * (2 * x + 1) / 6;
  };
  auto work = [&](auto self, __int128 l, __int128 r) -> __int128 {
    // std::cerr << l << ' ' << r << '\n';
    __int128 len = r - l + 1;
    __int128 cnt = len / w;
    if (cnt == 0) {
      return get1(r) - get1(l - 1);
    }
    __int128 LLen = cnt * w;
    __int128 dif = len - LLen;
    __int128 s = (dif + cnt - 1) / cnt - 1;
    if (s < 0) s = 0;
    __int128 t = len;
    __int128 ans = (r + l) * len / 2 * (s + 1) + (cnt * (len - (r + l)) * s * (s + 1) / 2 - get2(s) * cnt * cnt) / 2;
    // std::cerr << l << ' ' << r << ' ' << ans << '\n';
    if (len < w) return ans;
    return ans + self(self, l + (s + 1) * cnt, r);
  };
  auto work2 = [&](auto self, int l, int r) -> __int128 {
    // if (r - l + 1 < w) return 0;
    // _tot++;
    int len = (r - l + 1) / w;
    return get1(r) - get1(l - 1) + (r - l + 1 < w ? 0 : self(self, l + len, r));
  };
  std::cin >> n >> w;
  write(work(work, 1, n));
  std::cout << '\n';
  // write(work2(work2, 1, n));
  // std::cout << '\n';
  // std::cout << work(work, 1, n) << '\n';
}

int32_t main() {
  // std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}