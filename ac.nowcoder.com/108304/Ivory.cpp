#include <bits/stdc++.h>
#include <chrono>
#define ll long long
#define P 998244353
using namespace std;
using ull = unsigned long long;

namespace FastIO {
	constexpr int LEN = 1 << 20;
	char in[LEN + 1], out[LEN + 1];
	char *pin = in, *pout = out, *ein = in, *eout = out + LEN;

	char gc() { return pin == ein && (ein = (pin = in) + fread(in, 1, LEN, stdin), ein == in) ? EOF : *pin ++; }
	void pc(char c) { pout == eout && (fwrite(out, 1, LEN, stdout), pout = out); (*pout ++) = c; return; }
	struct Flush { ~Flush() { fwrite(out, 1, pout - out, stdout); pout = out; return; } } _flush;

	template<typename T> T Read() {
		T x = 0; int f = 1; char ch = gc();
		while (ch < '0' || ch > '9') f = (ch == '-' ? (~f + 1) : f), ch = gc();
		while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc();
		return x * f;
	}
	void Read(char *s) {
		char ch = gc();
		while (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') ch = gc();
		while ((ch != EOF) && !(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t')) *s = ch, s ++, ch = gc();
		*s = '\0'; return;
	}
	template<typename T> void Read(T &x) { x = Read<T>(); return; }
	template<typename T, typename ...Args>
	void Read(T &x, Args &...args) { Read(x), Read(args...); return; }
	template<typename T> void Write(T x) {
		static char stk[40]; int tp = 0;
		if (x < 0) pc('-'), x = ~x + 1;
		do stk[tp++] = x % 10 + 48, x /= 10; while (x);
		while (tp --) pc(stk[tp]);
		return;
	}
	void Write(char ch) { pc(ch); return; }
	void Write(const char *s) {
		while (*s != '\0') pc(*s), s ++;
		return;
	}
	void Puts(const char *s) {
		Write(s), pc('\n'); return;
	}
	template<typename T, typename ...Args>
	void Write(T x, Args ...args) { Write(x), Write(args...); return; }
} using namespace FastIO;

void YES(bool f = true) {
	f ? Puts("YES") : Puts("NO");
	return;
}
void NO(bool f = true) {
	YES(!f);
	return;
}
void Yes(bool f = true) {
	f ? Puts("Yes") : Puts("No");
	return;
}
void No(bool f = true) {
	Yes(!f);
	return;
}
void yes(bool f = true) {
	f ? Puts("yes") : Puts("no");
	return;
}
void no(bool f = true) {
	yes(!f);
	return;
}

const vector<int> small_primes = {
	2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,
	47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107,
	109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
	191, 193, 197, 199, 211, 223, 223, 229, 233, 239, 241, 251, 257, 263,
	269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
	353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
	439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 507, 521,
	523, 541, 547, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617,
	619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709,
	719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811,
	821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907,
	911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

ll power(ll a, __int128 b, ll p) {
	ll res = 1;
	a %= p;
	while (b > 0) {
		if (b & 1)
			res = (__int128)res * a % p;
		a = (__int128)a * a % p;
		b >>= 1;
	}
	return res;
}

// ll gcd(ll a, ll b) {
//   if (!a | !b)
//     return a + b;
//   int az = __builtin_ctzll(a);
//   int bz = __builtin_ctzll(b);
//   int z = std::min(az, bz);
//   a >>= az, b >>= bz;
//   while (a != b) {
//     int diff = b - a;
//     az = __builtin_ctzll(diff);
//     b = std::min(a, b), a = std::abs(diff) >> az;
//   }
//   return a << z;
// }

#define int long long
int gcd(int a, int b) {
	if (!a | !b)
		return a + b;
	int az = __builtin_ctzll(a);
	int bz = __builtin_ctzll(b);
	int z = min(az, bz);
	a >>= az, b >>= bz;
	while (a != b) {
		int diff = b - a;
		az = __builtin_ctzll(diff);
		b = min(a, b), a = abs(diff) >> az;
	}
	return a << z;
}
#undef int

// ll gcd(ll a, ll b) {
// #define tz __builtin_ctzll
// 	if (!a || !b) return a | b;
// 	int t = tz(a | b);
// 	a >>= tz(a);
// 	while (b) {
// 		b >>= tz(b);
// 		if (a > b) swap(a, b);
// 		b -= a;
// 	}
// 	return a << t;
// #undef tz
// }

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
			for (auto i:small_primes)
			{
				if (i*i>n)break;
				p.push_back(i);
				while(n%i==0)n/=i;
					
			}
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



using u64 = unsigned long long;
using u32 = unsigned;
using u128 = __uint128_t;

template<class U0, class U1>
struct Montgomery {
	constexpr static unsigned B0 = sizeof(U0) * 8U;
	U0 n, nr, rs, np;
	
	constexpr Montgomery(const U0 &Mod) {
		SetMod(Mod);
	}
	
	constexpr U0 GetMod() const noexcept {
		return n;
	}
	constexpr void SetMod(const U0& Mod) {
		assert(Mod >= 2), assert(Mod % 2 == 1);
		assert((Mod >> (B0 - 2)) == 0);
		n = nr = Mod, rs = -static_cast<U1>(n) % n;
		for (u32 i = 0; i < __lg(B0); i ++) {
			nr *= 2 - n * nr;
		}
		np = Reduce(static_cast<U0>(1), rs);
	}
	constexpr U0 Reduce(const U0& x) const noexcept {
		const U0 q = x * nr;
		const U0 m = (static_cast<U1>(q) * n) >> B0;
		return n - m;
	}
	constexpr U0 Reduce(const U0& x, const U0& y) const noexcept {
		const U1 t = static_cast<U1>(x) * y;
		const U0 c = t, d = t >> B0;
		const U0 q = c * nr;
		const U0 m = (static_cast<U1>(q) * n) >> B0;
		return d + n - m;
	}
	constexpr U0 Reduce(const U0& x, const U0& y, const U0& z) const noexcept {
		const U1 t = static_cast<U1>(x) * y;
		const U0 c = t, d = t >> B0;
		const U0 q = c * nr;
		const U0 m = (static_cast<U1>(q) * n) >> B0;
		return z + d + n - m;
	}
	constexpr U0 val(const U0& x) const noexcept {
		const u64 t = Reduce(x);
		return (t == n) ? static_cast<U0>(0) : t;
	}
	constexpr U0 zero() const noexcept {
		return static_cast<U0>(0);
	}
	constexpr U0 one() const noexcept {
		return np;
	}
	constexpr U0 raw(const U0& x) const noexcept {
		return Reduce(x, rs);
	}
	template<class U> requires std::unsigned_integral<U>
	constexpr U0 trans(const U& x) const noexcept {
		if (__builtin_expect(x < n, 1)) {
			return raw(x);
		}
		return Reduce(x % n, rs);
	}
	template<class S> requires std::signed_integral<S>
	constexpr U0 trans(S x) const noexcept {
		if (__builtin_expect(0 <= x && x < static_cast<S>(n), 1)) {
			return Raw(x);
		}
		if ((x %= static_cast<S>(n)) < 0) {
			(x += static_cast<S>(n)) %= static_cast<S>(n);
		}
		return Reduce(x, rs);
	}
	constexpr U0 neg(const U0& x) const noexcept {
		return (x != 0) ? (2 * n - x) : x;
	}
	constexpr U0 inc(const U0& x) const noexcept {
		return add(x, np);
	}
	constexpr U0 dec(const U0& x) const noexcept {
		return sub(x, np);
	}
	constexpr U0 add(const U0& x, const U0& y) const noexcept {
		return (x + y >= 2 * n) ? (x + y - 2 * n) : (x + y);
	}
	constexpr U0 sub(const U0& x, const U0& y) const noexcept {
		return (x < y) ? (x - y + 2 * n) : (x - y);
	}
	constexpr U0 mul(const U0& x, const U0& y) const noexcept {
		return Reduce(x, y);
	}
	constexpr U0 mul_add(const U0& x, const U0& y, const U0& z) const noexcept {
		return Reduce(x, y, z);
	}
	constexpr bool same(const U0& x, const U0& y) const noexcept {
		const U0 dif = x - y;
		return (dif == 0) || (dif == n) || (dif == -n);
	}
};


constexpr bool Is_Prime(u64 x) noexcept {
	if (x <= 1) {
		return false;
	}
	if (x % 2 == 0) {
		return x == 2;
	}
	
	constexpr array<u64, 10> Base{2, 7, 61, 2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	const u32 s = __builtin_ctzll(x - 1);
	const u64 d = (x - 1) >> s;
	const int q = 63 ^ __builtin_clzll(d);
	const Montgomery<u64, u128> Mod(x);
	const u32 l = (x >> 32) ? 3 : 0;
	const u32 r = (x >> 32) ? 10 : 3;
	for (u32 _ = l; _ < r; _ ++) {
		u64 base = Base[_];
		if (base % x == 0) {
			continue;
		}
		base = Mod.trans(base);
		u64 a = base;
		for (int i = q - 1; ~i; i --) {
			a = Mod.mul(a, a);
			if ((d >> i) & 1) {
				a = Mod.mul(a, base);
			}
		}
		if (Mod.same(a, Mod.one())) {
			continue;
		}
		for (u32 t = 1; t < s && !Mod.same(a, x - Mod.one()); ++ t) {
			a = Mod.mul(a, a);
		}
		if (!Mod.same(a, x - Mod.one())) {
			return false;
		}
	}
	return true;
}

template<bool sorted>
vector<pair<u64, u32>> Factorize(u64 n) {
	vector<pair<u64, u32>> ans;
	if (n % 2 == 0) {
		u32 z = __builtin_ctzll(n);
		ans.push_back({2ULL, z}), n >>= z;
	}
	auto upd = [&](const u64& x) {
		for (auto &[p, c] : ans) {
			if (x == p) {
				++ c;
				return;
			}
		}
		ans.push_back({x, 1});
	};
	auto Pollard_Rho = [&](const u64& n) {
		if (n % 2 == 0) {
			return 2ULL;
		}
		const Montgomery<u64, u128> Mod(n);
		const u64 C1 = 1, C2 = 2, M = 512;
		u64 Z1 = 1, Z2 = 2, ans = 0;
		auto find = [&]() {
			u64 z1 = Z1, z2 = Z2;
			for (u64 k = M; ; k *= 2) {
				const u64 x1 = z1 + n, x2 = z2 + n;
				for (u64 j = 0; j < k; j += M) {
					const u64 y1 = z1, y2 = z2;
					u64 q1 = 1, q2 = 2;
					z1 = Mod.mul_add(z1, z1, C1), z2 = Mod.mul_add(z2, z2, C2);
					for (u64 i = 0; i < M; ++i) {
						u64 t1 = x1 - z1, t2 = x2 - z2;
						z1 = Mod.mul_add(z1, z1, C1), z2 = Mod.mul_add(z2, z2, C2);
						q1 = Mod.mul(q1, t1), q2 = Mod.mul(q2, t2);
					}
					q1 = Mod.mul(q1, x1 - z1), q2 = Mod.mul(q2, x2 - z2);
					const u64 q3 = Mod.mul(q1, q2), g3 = std::gcd(n, q3);
					if (g3 == 1) {
						continue;
					}
					if (g3 != n) {
						ans = g3;
						return;
					}
					const u64 g1 = std::gcd(n, q1);
					const u64 g2 = std::gcd(n, q2);
					const u64 C = g1 != 1 ? C1 : C2;
					const u64 x = g1 != 1 ? x1 : x2;
					u64 z = g1 != 1 ? y1 : y2;
					u64 g = g1 != 1 ? g1 : g2;
					if (g == n) {
						do {
							z = Mod.mul_add(z, z, C);
							g = std::gcd(n, x - z);
						} while (g == 1);
					}
					if (g != n) {
						ans = g;
						return;
					}
					Z1 += 2, Z2 += 2;
					return;
				}
			}
    };
    do {
    	find();
    } while (!ans);
    return ans;
	};
	auto DFS = [&](auto &&self, const u64 &n) -> void {
		if (Is_Prime(n)) {
			return upd(n);
		}
		u64 d = Pollard_Rho(n);
		self(self, d), self(self, n / d);
	};
	if (n > 1) {
		DFS(DFS, n); 
	}
	if constexpr (sorted) {
		sort(ans.begin(), ans.end());
	}
	return ans;
}

//std::map<i64, std::vector<i64>> mp;

void solve() {
	ll a, b, c, d, ans = 1;
	bool flag = 1;
	// cin >> a >> b >> c >> d;
  a = Read<i64>();
  b = Read<i64>();
  c = Read<i64>();
  d = Read<i64>();
	ll g = gcd(a, c);
	if (g == 1) {
		// cout << "1\n";
    Write(1, "\n");
		return;
	}
	if (a==c)
	{
    Write(power(a, std::min(b, d), P), "\n");
		// cout<<power(a,min(b,d),P)<<'\n';
		return ;
	}
	// set<ll> primes;
	// fac(g, primes);
//	if (mp.count(g)) {
//		primes = mp[g];
//	} else {
		// primes = factorize(g);
    auto start = std::chrono::high_resolution_clock::now();
    auto primes = Factorize<true>(g);
    auto end = std::chrono::high_resolution_clock::now();
    // Write(end - start);
    // std::cout << 
    Write(end - start, "\n");
    //  << '\n';
//		mp[g] = primes;
//	}
	for (auto [p, _c] : primes) {
		ll A = 0, x = a;
		while (a % p == 0) {
			A++;
			a /= p;
		}
		ll C = 0;
		x = c;
		while (c % p == 0) {
			C++;
			c /= p;
		}
		__int128 exp = min((__int128)b * A, (__int128)d * C);
		if (p % P == 0) {
			flag = 0;
			break;
		}
		ans = (__int128)ans * power(p % P, exp, P) % P;
	}
	// cout << (flag ? ans : 0) << '\n';
  Write(flag ? ans : 0, "\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = Read<int>();
	// cin >> T;
	while (T--)
		solve();
	return 0;
}