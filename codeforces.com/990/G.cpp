// date: 2024-12-12 21:28:17
// tag: 点分治，gcd性质，数论
// 一定要注意！
// 点分治处理当前边和过去边的时候，千万要注意复杂度！这一步最多允许两个log！
// 点分治原本的 nlogn 是逃不掉的，那一步一定要调控复杂度
// 考虑当前是当前分治根的最后一条边，这里只允许log！
// 何况点分治常数本身就大
// 八成是那里错了，我估计不会再忘记更新maxx了，草

#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5;

std::vector<int> g[N + 1];
int a[N + 1], n, maxx[N + 1], siz[N + 1], vis[N + 1], sum = 0, rt = 0;
int ans[N + 1];

void getrt(int u, int p) {
  siz[u] = 1;
  maxx[u] = 0; // 就差那么一点点
  for (int v : g[u]) {
    if (v != p && !vis[v]) {
      getrt(v, u);
      siz[u] += siz[v];
      maxx[u] = std::max(maxx[u], siz[v]);
    }
  }
  maxx[u] = std::max(maxx[u], sum - siz[u]);
  if (maxx[u] < maxx[rt]) {
    rt = u;
  }
}

int nowcnt[N + 1], allcnt[N + 1];
std::set<int> nowgcd, allgcd;
// std::unordered_map<int, int> nowcnt, allcnt;

void calc(int u, int p, int gcd) {
  // std::cout << u << '\n';
  gcd = std::gcd(gcd, a[u]);
  nowgcd.insert(gcd);
  nowcnt[gcd]++;
  allgcd.insert(gcd);
  allcnt[gcd]++;
  ans[gcd]++;
  for (int v : g[u]) {
    if (v != p && !vis[v]) {
      calc(v, u, gcd);
    }
  }
}

int tot = 0;

void work(int u, int p) {
  // std::cout << u << '\n';
  vis[u] = 1;
  ans[a[u]]++;
  allgcd.clear();
  nowgcd.clear();
  tot += siz[u];
  for (int v : g[u]) {
    if (v != p && !vis[v]) {
      calc(v, u, a[u]);
      // 这里如果直接和allcnt循环会退化到log^3v，总复杂度就4-5个log了，离谱，离大谱
      for (auto &x : nowgcd) {
        for (auto &y : nowgcd) {
          if (x == y) {
            ans[x] -= nowcnt[x] * (nowcnt[x] - 1) / 2;
          } else if (x > y) {
            ans[std::gcd(x, y)] -= nowcnt[x] * nowcnt[y];
          } else {
            break;
          }
        }
      }
      for (auto &x : nowgcd) {
        nowcnt[x] = 0;
      }
      nowgcd.clear();
    }
  }
  for (auto &x : allgcd) {
    for (auto &y : allgcd) {
      if (x == y) {
        ans[x] += allcnt[x] * (allcnt[x] - 1) / 2;
      } else if (x > y) {
        ans[std::gcd(x, y)] += allcnt[x] * allcnt[y];
      } else {
        break;
      }
    }
  }
  for (auto &x : allgcd) {
    allcnt[x] = 0;
  }
  allgcd.clear();
  for (int v : g[u]) {
    if (v != p && !vis[v]) {
      sum = siz[v];
      rt = 0;
      getrt(v, 0);
      work(rt, 0);
    }
  }
}

void solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    ans[i] = maxx[i] = vis[i] = 0;
  }
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  sum = n, rt = 0;
  maxx[rt] = INT_MAX;
  getrt(1, 0);
  work(rt, 0);
  for (int i = 1; i <= N; i++) {
    if (ans[i]) {
      std::cout << i << ' ' << ans[i] << '\n';
    }
  }
  // std::cout << tot << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}