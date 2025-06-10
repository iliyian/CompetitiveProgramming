// date: 2025-04-10 09:39:30
// tag: 怎么说呢？基于可变大小的bitset优化和主定理优化的树上可行性01背包。而为了降低常数有必要按照2^k的siz开很多个bitset。其实整体还是显然的吧？

#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6 / 2;

std::bitset<1> f1;
std::bitset<2> f2;
std::bitset<4> f4;
std::bitset<8> f8;
std::bitset<16> f16;
std::bitset<32> f32;
std::bitset<64> f64;
std::bitset<128> f128;
std::bitset<256> f256;
std::bitset<512> f512;
std::bitset<1024> f1024;
std::bitset<2048> f2048;
std::bitset<4096> f4096;
std::bitset<8192> f8192;
std::bitset<16384> f16384;
std::bitset<32768> f32768;
std::bitset<65536> f65536;
std::bitset<131072> f131072;
std::bitset<262144> f262144;
std::bitset<524288> f524288;
std::bitset<1048576> f1048576;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> a(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  std::vector<int> siz(n + 1);
  int ans = 0;
  auto solve = [&](std::vector<int> &v, int sum, int ss) {
    if (sum < 1) {
      f1[0] = 1;
      for (int i : v) f1 |= f1 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f1[i]) mx = std::max(mx, i * (ss - i)); f1.reset(); return mx;
    }
    if (sum < 2) {
      f2[0] = 1;
      for (int i : v) f2 |= f2 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f2[i]) mx = std::max(mx, i * (ss - i)); f2.reset(); return mx;
    }
    if (sum < 4) {
      f4[0] = 1;
      for (int i : v) f4 |= f4 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f4[i]) mx = std::max(mx, i * (ss - i)); f4.reset(); return mx;
    }
    if (sum < 8) {
      f8[0] = 1;
      for (int i : v) f8 |= f8 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f8[i]) mx = std::max(mx, i * (ss - i)); f8.reset(); return mx;
    }
    if (sum < 16) {
      f16[0] = 1;
      for (int i : v) f16 |= f16 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f16[i]) mx = std::max(mx, i * (ss - i)); f16.reset(); return mx;
    }
    if (sum < 32) {
      f32[0] = 1;
      for (int i : v) f32 |= f32 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f32[i]) mx = std::max(mx, i * (ss - i)); f32.reset(); return mx;
    }
    if (sum < 64) {
      f64[0] = 1;
      for (int i : v) f64 |= f64 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f64[i]) mx = std::max(mx, i * (ss - i)); f64.reset(); return mx;
    }
    if (sum < 128) {
      f128[0] = 1;
      for (int i : v) f128 |= f128 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f128[i]) mx = std::max(mx, i * (ss - i)); f128.reset(); return mx;
    }
    if (sum < 256) {
      f256[0] = 1;
      for (int i : v) f256 |= f256 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f256[i]) mx = std::max(mx, i * (ss - i)); f256.reset(); return mx;
    }
    if (sum < 512) {
      f512[0] = 1;
      for (int i : v) f512 |= f512 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f512[i]) mx = std::max(mx, i * (ss - i)); f512.reset(); return mx;
    }
    if (sum < 1024) {
      f1024[0] = 1;
      for (int i : v) f1024 |= f1024 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f1024[i]) mx = std::max(mx, i * (ss - i)); f1024.reset(); return mx;
    }
    if (sum < 2048) {
      f2048[0] = 1;
      for (int i : v) f2048 |= f2048 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f2048[i]) mx = std::max(mx, i * (ss - i)); f2048.reset(); return mx;
    }
    if (sum < 4096) {
      f4096[0] = 1;
      for (int i : v) f4096 |= f4096 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f4096[i]) mx = std::max(mx, i * (ss - i)); f4096.reset(); return mx;
    }
    if (sum < 8192) {
      f8192[0] = 1;
      for (int i : v) f8192 |= f8192 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f8192[i]) mx = std::max(mx, i * (ss- i)); f8192.reset(); return mx;
    }
    if (sum < 16384) {
      f16384[0] = 1;
      for (int i : v) f16384 |= f16384 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f16384[i]) mx = std::max(mx, i * (ss - i)); f16384.reset(); return mx;
    }
    if (sum < 32768) {
      f32768[0] = 1;
      for (int i : v) f32768 |= f32768 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f32768[i]) mx = std::max(mx, i * (ss - i)); f32768.reset(); return mx;
    }
    if (sum < 65536) {
      f65536[0] = 1;
      for (int i : v) f65536 |= f65536 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f65536[i]) mx = std::max(mx, i * (ss - i)); f65536.reset(); return mx;
    }
    if (sum < 131072) {
      f131072[0] = 1;
      for (int i : v) f131072 |= f131072 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f131072[i]) mx = std::max(mx, i * (ss - i)); f131072.reset(); return mx;
    }
    if (sum < 262144) {
      f262144[0] = 1;
      for (int i : v) f262144 |= f262144 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f262144[i]) mx = std::max(mx, i * (ss - i)); f262144.reset(); return mx;
    }
    if (sum < 524288) {
      f524288[0] = 1;
      for (int i : v) f524288 |= f524288 << i; int mx = 0;
      for (int i = 1; i <= sum; i++) if (f524288[i]) mx = std::max(mx, i * (ss - i)); f524288.reset(); return mx;
    }
  };
  auto dfs = [&](auto self, int u) -> void {
    siz[u] = 1;
    std::vector<int> vec, v;
    int mxv = 0;
    for (int v : g[u]) {
      self(self, v);
      siz[u] += siz[v];
      vec.push_back(siz[v]);
      mxv = std::max(mxv, siz[v]);
    }
    if (mxv >= (siz[u] - 1 - mxv)) {
      ans += mxv * (siz[u] - 1 - mxv);
      return;
    }
    std::sort(vec.begin(), vec.end());
    int prv = -1, cnt = 0;
    for (auto i : vec) {
      if (prv == i) {
      } else if (prv != -1) {
        for (int k = 1; cnt > k; k *= 2) {
          v.push_back(k * prv);
          cnt -= k;
        }
        v.push_back(cnt * prv);
        cnt = 0;
      }
      prv = i;
      cnt++;
    }

    for (int k = 1; cnt > k; k *= 2) {
      v.push_back(k * prv);
      cnt -= k;
    }
    v.push_back(cnt * prv);
    cnt = 0;

    ans += solve(v, siz[u] / 2, siz[u] - 1);
  };
  dfs(dfs, 1);
  std::cout << ans << '\n';
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