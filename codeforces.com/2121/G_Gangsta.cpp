#include <bits/stdc++.h>
#define int long long

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  std::vector<std::array<int, 2>> s(n, {0, 0});
  std::vector<int> d(n);
  std::array<Fenwick<int>, 3> fen;
  fen.fill(Fenwick<int>(n * 2));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i) {
      s[i] = s[i - 1];
    }
    s[i][str[i] - '0']++;
    d[i] = s[i][1] - s[i][0];
    ans += fen[2].sum(d[i] + n) * s[i][1] - fen[1].sum(d[i] + n) + fen[2].rangeSum(d[i] + n, n * 2) * s[i][0] - fen[0].rangeSum(d[i] + n, n * 2);
    ans += std::max(s[i][1], s[i][0]);
    for (int j = 0; j < 3; j++) {
      fen[j].add(d[i] + n, (j == 2 ? 1 : s[i][j]));
    }
  }
  std::cout << ans << '\n';
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