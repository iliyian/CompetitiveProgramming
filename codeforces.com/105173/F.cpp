#include <bits/stdc++.h>
#define int long long

using i64 = long long;

i64 mul(i64 a, i64 b, i64 m) {
    return static_cast<__int128>(a) * b % m;
}
i64 power(i64 a, i64 b, i64 m) {
    i64 res = 1 % m;
    for (; b; b >>= 1, a = mul(a, a, m))
        if (b & 1)
            res = mul(res, a, m);
    return res;
}
bool isprime(i64 n) {
    if (n < 2)
        return false;
    static constexpr int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int s = __builtin_ctzll(n - 1);
    i64 d = (n - 1) >> s;
    for (auto a : A) {
        if (a == n)
            return true;
        i64 x = power(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool ok = false;
        for (int i = 0; i < s - 1; ++i) {
            x = mul(x, x, n);
            if (x == n - 1) {
                ok = true;
                break;
            }
        }
        if (!ok)
            return false;
    }
    return true;
}
std::vector<i64> factorize(i64 n) {
    std::vector<i64> p;
    std::function<void(i64)> f = [&](i64 n) {
        if (n <= 10000) {
            for (int i = 2; i * i <= n; ++i)
                for (; n % i == 0; n /= i)
                    p.push_back(i);
            if (n > 1)
                p.push_back(n);
            return;
        }
        if (isprime(n)) {
            p.push_back(n);
            return;
        }
        auto g = [&](i64 x) {
            return (mul(x, x, n) + 1) % n;
        };
        i64 x0 = 2;
        while (true) {
            i64 x = x0;
            i64 y = x0;
            i64 d = 1;
            i64 power = 1, lam = 0;
            i64 v = 1;
            while (d == 1) {
                y = g(y);
                ++lam;
                v = mul(v, std::abs(x - y), n);
                if (lam % 127 == 0) {
                    d = std::gcd(v, n);
                    v = 1;
                }
                if (power == lam) {
                    x = y;
                    power *= 2;
                    lam = 0;
                    d = std::gcd(v, n);
                    v = 1;
                }
            }
            if (d != n) {
                f(d);
                f(n / d);
                return;
            }
            ++x0;
        }
    };
    f(n);
    std::sort(p.begin(), p.end());
    return p;
}

std::vector<std::pair<int, int>> work(int x) {
	auto v = factorize(x);
	std::vector<std::pair<int, int>> f;
	int prv = 0;
	for (int i : v) {
		if (i != prv) {
			f.push_back({i, 1});
		} else {
			f.back().second++;
		}
		prv = i;
	}
	return f;
}

using i128 = __int128;

void solve() {
  int p, q, k;
  std::cin >> p >> q >> k;
	auto fp = work(p), fk = work(k);
  int ans = 0;
	std::set<int> s;
	for (auto [v, cnt] : fk) {
		s.insert(v);
	}
	std::set<int> st;
	auto dfs2 = [&](auto self, i128 u, int idx) -> void {
		if (idx == fp.size()) {
			ans++;
			return;
		}
		if (s.count(fp[idx].first)) {
			self(self, u, idx + 1);
			return;
		}
		i128 vv = 1;
		auto [v, mx] = fp[idx];
		for (int j = 0; j <= mx && u * vv <= q; j++, vv *= v) {
			self(self, u * vv, idx + 1);
		}
	};
	auto dfs = [&](auto self, i128 u, int idx) -> void {
		if (idx < fk.size()) {
			auto [v, mx] = fk[idx];
			i128 vv = 1;
			for (int j = 0; u * vv <= q; j++, vv *= v) {
				self(self, u * vv, idx + 1);
			}
		} else {
			dfs2(dfs2, u, 0);
		}
  };
  dfs(dfs, 1, 0);
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