#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// #define int ll

bool dbg = false;

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr << __LINE__ << " " << #x << " " << x << endl
#else
#define dmp(x) void(0)
#endif

template <class t, class u> bool chmax(t &a, u b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template <class t, class u> bool chmin(t &a, u b) {
  if (b < a) {
    a = b;
    return true;
  } else
    return false;
}

template <class t> using vc = vector<t>;
template <class t> using vvc = vc<vc<t>>;

using pi = pair<int, int>;
using vi = vc<int>;
using vvi = vc<vc<int>>;

template <class t, class u>
ostream &operator<<(ostream &os, const pair<t, u> &p) {
  return os << "{" << p.a << "," << p.b << "}";
}

template <class t> ostream &operator<<(ostream &os, const vc<t> &v) {
  os << "{";
  for (auto e : v)
    os << e << ",";
  return os << "}";
}

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x, -1, sizeof(x))
#define zero(x) memset(x, 0, sizeof(x))
#ifdef LOCAL
void dmpr(ostream &os) { os << endl; }
template <class T, class... Args>
void dmpr(ostream &os, const T &t, const Args &...args) {
  os << t << " ";
  dmpr(os, args...);
}
#define dmp2(...) dmpr(cerr, __LINE__, ##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint = unsigned;
using ull = unsigned long long;

template <class t, size_t n>
ostream &operator<<(ostream &os, const array<t, n> &a) {
  return os << vc<t>(all(a));
}

ll rand_int(ll l, ll r) { //[l, r]
  // #ifdef LOCAL
  static mt19937_64 gen;
  /*#else
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  #endif*/
  return uniform_int_distribution<ll>(l, r)(gen);
}

ll rand_int(ll k) { //[0,k)
  return rand_int(0, k - 1);
}
string rand_string(int n, char lw, char up) {
  string s(n, '?');
  rep(i, n) s[i] = rand_int(lw, up);
  return s;
}

int current_run_id, run_batch_size = 1000;
int calc_random_limit() { return current_run_id / run_batch_size + 1; }
template <class t> void generate_single(t &a) {
  a = rand_int(1, calc_random_limit());
}
void generate_single(string &a) {
  int n;
  generate_single(n);
  a = rand_string(n, 'a', 'b');
}
template <class t, class u> void generate_single(pair<t, u> &a) {
  generate_single(a.a);
  generate_single(a.b);
}
// https://trap.jp/post/1224/
template <class... Args> void input(Args &...a) {
  if (dbg) {
    (generate_single(a), ...);
  } else {
#ifdef USE_FAST_IO
    sc.read(a...);
#else
    (cin >> ... >> a);
#endif
  }
}
#define INT(...)                                                               \
  int __VA_ARGS__;                                                             \
  input(__VA_ARGS__)
#define LL(...)                                                                \
  ll __VA_ARGS__;                                                              \
  input(__VA_ARGS__)
#define ULL(...)                                                               \
  ull __VA_ARGS__;                                                             \
  input(__VA_ARGS__)
#define STR(...)                                                               \
  string __VA_ARGS__;                                                          \
  input(__VA_ARGS__)
#define CHR(...)                                                               \
  char __VA_ARGS__;                                                            \
  input(__VA_ARGS__)
#define DBL(...)                                                               \
  double __VA_ARGS__;                                                          \
  input(__VA_ARGS__)
#define LD(...)                                                                \
  ld __VA_ARGS__;                                                              \
  input(__VA_ARGS__)
#define overload3(a, b, c, d, ...) d
#define VI2(name, size)                                                        \
  vi name(size);                                                               \
  rep(i_##name, size) input(name[i_##name]);
#define VI3(name, size, offset)                                                \
  vi name(size);                                                               \
  rep(i_##name, size) input(name[i_##name]), name[i_##name] += offset;
#define VI(...) overload3(__VA_ARGS__, VI3, VI2)(__VA_ARGS__)
#define VPI(name, size)                                                        \
  vc<pi> name(size);                                                           \
  rep(i_##name, size) input(name[i_##name].a, name[i_##name].b);
#define VVI(name, sizeN, sizeM)                                                \
  vvi name(sizeN, vi(sizeM));                                                  \
  rep(i_##name, sizeN) rep(j_##name, sizeM) input(name[i_##name][j_##name]);
#define VS(name, size)                                                         \
  vc<string> name(size);                                                       \
  rep(i_##name, size) input(name[i_##name]);
#define VMI(name, size)                                                        \
  vc<mint> name(size);                                                         \
  rep(i_##name, size) {                                                        \
    INT(tmp_##name);                                                           \
    name[i_##name] = tmp_##name;                                               \
  };

#define overload5(a, b, c, d, e, f, ...) f
#define VVC4(type, name, sizeN, sizeM) vvc<type> name(sizeN, vc<type>(sizeM));
#define VVC5(type, name, sizeN, sizeM, ini)                                    \
  vvc<type> name(sizeN, vc<type>(sizeM, ini));
#define VVC(...) overload5(__VA_ARGS__, VVC5, VVC4)(__VA_ARGS__)

template <class T> T vvvc(T v) { return v; }

template <class T, class... Args> auto vvvc(int n, T v, Args... args) {
  return vector(n, vvvc(v, args...));
}

template <int i, class T> void print_tuple(ostream &, const T &) {}

template <int i, class T, class H, class... Args>
void print_tuple(ostream &os, const T &t) {
  if (i)
    os << ",";
  os << get<i>(t);
  print_tuple<i + 1, T, Args...>(os, t);
}

template <class... Args>
ostream &operator<<(ostream &os, const tuple<Args...> &t) {
  os << "{";
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << "}";
}

void printsuc(int suc) {
#ifdef USE_FAST_IO
  if (suc == 1)
    pr.write('\n');
  if (suc == 2)
    pr.write(' ');
#else
  if (suc == 1) {
    if (dbg)
      cout << endl;
    else {
#ifdef LOCAL
      cout << endl;
#else
      cout << "\n";
#endif
    }
  }
  if (suc == 2)
    cout << " ";
#endif
}

template <class t> void print_single(t x, int suc = 1) {
#ifdef USE_FAST_IO
  pr.write(x);
#else
  cout << x;
#endif
  printsuc(suc);
}

template <class t, class u>
void print_single(const pair<t, u> &p, int suc = 1) {
  print_single(p.a, 2);
  print_single(p.b, suc);
}

template <class T> void print_single(const vector<T> &v, int suc = 1) {
  rep(i, v.size()) print_single(v[i], i == int(v.size()) - 1 ? 3 : 2);
  printsuc(suc);
}

template <class T, size_t N>
void print_single(const array<T, N> &v, int suc = 1) {
  rep(i, N) print_single(v[i], i == int(N) - 1 ? 3 : 2);
  printsuc(suc);
}

template <class T> void print(const T &t) { print_single(t); }

template <class T, class... Args> void print(const T &t, const Args &...args) {
  print_single(t, 2);
  print(args...);
}

template <class T> void printvv(const vvc<T> &vs) {
  for (const auto &row : vs)
    print(row);
}

string readString() {
  string s;
  cin >> s;
  return s;
}

template <class T> T sq(const T &t) { return t * t; }

void YES(bool ex = true) {
  cout << "YES\n";
  if (ex)
    exit(0);
#ifdef LOCAL
  cout.flush();
#endif
}
void NO(bool ex = true) {
  cout << "NO\n";
  if (ex)
    exit(0);
#ifdef LOCAL
  cout.flush();
#endif
}
void Yes(bool ex = true) {
  cout << "Yes\n";
  if (ex)
    exit(0);
#ifdef LOCAL
  cout.flush();
#endif
}
void No(bool ex = true) {
  cout << "No\n";
  if (ex)
    exit(0);
#ifdef LOCAL
  cout.flush();
#endif
}
// #define CAPITAL
/*
void yes(bool ex=true){
        #ifdef CAPITAL
        cout<<"YES"<<"\n";
        #else
        cout<<"Yes"<<"\n";
        #endif
        if(ex)exit(0);
        #ifdef LOCAL
        cout.flush();
        #endif
}
void no(bool ex=true){
        #ifdef CAPITAL
        cout<<"NO"<<"\n";
        #else
        cout<<"No"<<"\n";
        #endif
        if(ex)exit(0);
        #ifdef LOCAL
        cout.flush();
        #endif
}*/
void possible(bool ex = true) {
#ifdef CAPITAL
  cout << "POSSIBLE" << "\n";
#else
  cout << "Possible" << "\n";
#endif
  if (ex)
    exit(0);
#ifdef LOCAL
  cout.flush();
#endif
}
void impossible(bool ex = true) {
#ifdef CAPITAL
  cout << "IMPOSSIBLE" << "\n";
#else
  cout << "Impossible" << "\n";
#endif
  if (ex)
    exit(0);
#ifdef LOCAL
  cout.flush();
#endif
}

constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }

const ll infLL = LLONG_MAX / 3;

#ifdef int
const int inf = infLL;
#else
const int inf = INT_MAX / 2 - 100;
#endif

int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int topbit(ull t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int botbit(ull a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
int popcount(ull t) { return __builtin_popcountll(t); }
int bitparity(ll t) { return __builtin_parityll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
ull umask(int i) { return (ull(1) << i) - 1; }
ll minp2(ll n) {
  if (n <= 1)
    return 1;
  else
    return ll(1) << (topbit(n - 1) + 1);
}

bool inc(int a, int b, int c) { return a <= b && b <= c; }

template <class S> void mkuni(S &v) {
  sort(all(v));
  v.erase(unique(all(v)), v.ed);
}

template <class t> bool isuni(vc<t> v) {
  int s = si(v);
  mkuni(v);
  return si(v) == s;
}

bool isperm(const vi &p) {
  int n = si(p);
  vc<bool> used(n);
  for (auto v : p) {
    if (!inc(0, v, n - 1))
      return false;
    if (used[v])
      return false;
    used[v] = true;
  }
  return true;
}

template <class t> void myshuffle(vc<t> &a) {
  rep(i, si(a)) swap(a[i], a[rand_int(0, i)]);
}

template <class S, class u> int lwb(const S &v, const u &a) {
  return lower_bound(all(v), a) - v.bg;
}
template <class t, class u> bool bis(const vc<t> &v, const u &a) {
  return binary_search(all(v), a);
}

// VERIFY: yosupo
// KUPC2017J
// AOJDSL1A
// without rank
struct unionfind {
  vi p, s;
  int c;
  unionfind(int n) : p(n, -1), s(n, 1), c(n) {}
  void clear() {
    fill(all(p), -1);
    fill(all(s), 1);
    c = si(p);
  }
  int find(int a) { return p[a] == -1 ? a : (p[a] = find(p[a])); }
  // set b to a child of a
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return false;
    p[b] = a;
    s[a] += s[b];
    c--;
    return true;
  }
  bool same(int a, int b) { return find(a) == find(b); }
  int sz(int a) { return s[find(a)]; }
};

vvc<int> readGraph(int n, int m) {
  vvc<int> g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    // sc.read(a,b);
    a--;
    b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  return g;
}

vvc<int> initUG(int n, const vc<pi> &es) {
  vvc<int> g(n);
  for (auto [a, b] : es) {
    g[a].pb(b);
    g[b].pb(a);
  }
  return g;
}

vvc<int> rand_tree(int n) {
  vvc<int> t(n);
  unionfind uf(n);
  while (uf.c > 1) {
    int a = rand_int(n);
    int b = rand_int(n);
    if (uf.unite(a, b)) {
      t[a].pb(b);
      t[b].pb(a);
    }
  }
  return t;
}

vvc<int> readTree(int n) {
  if (dbg) {
    return rand_tree(n);
  } else {
    return readGraph(n, n - 1);
  }
}

vi readRooted(int n) {
  assert(!dbg);
  vi par(n, -1);
  rng(i, 1, n) {
    input(par[i]);
    par[i]--;
    assert(inc(0, par[i], i - 1));
  }
  return par;
}

void printTree(const vvc<int> t) {
  int n = si(t);
  int degsum = 0;
  rep(i, n) degsum += si(t[i]);
  if (degsum == n - 1) {
    // directed
    rep(i, si(t)) for (auto j : t[i]) { print(i + 1, j + 1); }
  } else if (degsum == 2 * (n - 1)) {
    // undirected
    rep(i, si(t)) for (auto j : t[i]) if (i < j) { print(i + 1, j + 1); }
  } else {
    assert(false);
  }
}

template <class t> vc<t> presum(const vc<t> &a) {
  vc<t> s(si(a) + 1);
  rep(i, si(a)) s[i + 1] = s[i] + a[i];
  return s;
}
vc<ll> presum(const vi &a) {
  vc<ll> s(si(a) + 1);
  rep(i, si(a)) s[i + 1] = s[i] + a[i];
  return s;
}
// BIT で数列を管理するときに使う (CF850C)
template <class t> vc<t> predif(vc<t> a) {
  gnr(i, 1, si(a)) a[i] -= a[i - 1];
  return a;
}
template <class t> vvc<ll> imos(const vvc<t> &a) {
  int n = si(a), m = si(a[0]);
  vvc<ll> b(n + 1, vc<ll>(m + 1));
  rep(i, n) rep(j, m) b[i + 1][j + 1] =
      b[i + 1][j] + b[i][j + 1] - b[i][j] + a[i][j];
  return b;
}

// verify してないや
void transvvc(int &n, int &m) { swap(n, m); }
template <class t, class... Args>
void transvvc(int &n, int &m, vvc<t> &a, Args &...args) {
  assert(si(a) == n);
  vvc<t> b(m, vi(n));
  rep(i, n) {
    assert(si(a[i]) == m);
    rep(j, m) b[j][i] = a[i][j];
  }
  a.swap(b);
  transvvc(n, m, args...);
}
// CF854E
void rotvvc(int &n, int &m) { swap(n, m); }
template <class t, class... Args>
void rotvvc(int &n, int &m, vvc<t> &a, Args &...args) {
  assert(si(a) == n);
  vvc<t> b(m, vi(n));
  rep(i, n) {
    assert(si(a[i]) == m);
    rep(j, m) b[m - 1 - j][i] = a[i][j];
  }
  a.swap(b);
  rotvvc(n, m, args...);
}

// ソートして i 番目が idx[i]
// CF850C
template <class t> vi sortidx(const vc<t> &a) {
  int n = si(a);
  vi idx(n);
  iota(all(idx), 0);
  sort(all(idx), [&](int i, int j) { return a[i] < a[j]; });
  return idx;
}
// vs[i]=a[idx[i]]
// 例えば sortidx で得た idx を使えば単にソート列になって返ってくる
// CF850C
template <class t> vc<t> a_idx(const vc<t> &a, const vi &idx) {
  int n = si(a);
  assert(si(idx) == n);
  vc<t> vs(n);
  rep(i, n) vs[i] = a[idx[i]];
  return vs;
}
// CF850C
vi invperm(const vi &p) {
  int n = si(p);
  vi q(n);
  rep(i, n) q[p[i]] = i;
  return q;
}

template <class t, class s = t> s SUM(const vc<t> &a) {
  return accumulate(all(a), s(0));
}
template <class t, size_t K, class s = t> s SUM(const array<t, K> &a) {
  return accumulate(all(a), s(0));
}

template <class t> t MAX(const vc<t> &a) { return *max_element(all(a)); }

template <class t> pair<t, int> MAXi(const vc<t> &a) {
  auto itr = max_element(all(a));
  return mp(*itr, itr - a.bg);
}

template <class A> auto MIN(const A &a) { return *min_element(all(a)); }

template <class t> pair<t, int> MINi(const vc<t> &a) {
  auto itr = min_element(all(a));
  return mp(*itr, itr - a.bg);
}

vi vid(int n) {
  vi res(n);
  iota(all(res), 0);
  return res;
}

template <class S> void soin(S &s) { sort(all(s)); }

template <class S, class F> void soin(S &s, F &&f) {
  sort(all(s), forward<F>(f));
}

template <class S> S soout(S s) {
  soin(s);
  return s;
}

template <class S> void rein(S &s) { reverse(all(s)); }

template <class S> S reout(S s) {
  rein(s);
  return s;
}

template <class t, class u>
pair<t, u> &operator+=(pair<t, u> &a, pair<t, u> b) {
  a.a += b.a;
  a.b += b.b;
  return a;
}
template <class t, class u>
pair<t, u> &operator-=(pair<t, u> &a, pair<t, u> b) {
  a.a -= b.a;
  a.b -= b.b;
  return a;
}
template <class t, class u> pair<t, u> operator+(pair<t, u> a, pair<t, u> b) {
  return mp(a.a + b.a, a.b + b.b);
}
template <class t, class u> pair<t, u> operator-(pair<t, u> a, pair<t, u> b) {
  return mp(a.a - b.a, a.b - b.b);
}
template <class t, class u, class v>
pair<t, u> &operator*=(pair<t, u> &a, v b) {
  a.a *= b;
  a.b *= b;
  return a;
}
template <class t, class u, class v> pair<t, u> operator*(pair<t, u> a, v b) {
  return a *= b;
}
template <class t, class u> pair<t, u> operator-(pair<t, u> a) {
  return mp(-a.a, -a.b);
}
namespace std {
template <class t, class u> istream &operator>>(istream &is, pair<t, u> &a) {
  return is >> a.a >> a.b;
}
} // namespace std

template <class t, size_t n>
array<t, n> &operator+=(array<t, n> &a, const array<t, n> &b) {
  rep(i, n) a[i] += b[i];
  return a;
}
template <class t, size_t n>
array<t, n> &operator-=(array<t, n> &a, const array<t, n> &b) {
  rep(i, n) a[i] -= b[i];
  return a;
}
template <class t, size_t n, class v>
array<t, n> &operator*=(array<t, n> &a, v b) {
  rep(i, n) a[i] *= b;
  return a;
}
template <class t, size_t n>
array<t, n> operator+(array<t, n> a, const array<t, n> &b) {
  return a += b;
}
template <class t, size_t n>
array<t, n> operator-(array<t, n> a, const array<t, n> &b) {
  return a -= b;
}
template <class t, size_t n, class v>
array<t, n> operator*(array<t, n> a, v b) {
  return a *= b;
}

template <class t> t gpp(vc<t> &vs) {
  assert(si(vs));
  t res = move(vs.back());
  vs.pop_back();
  return res;
}

template <class t, class u> void pb(vc<t> &a, const vc<u> &b) {
  a.insert(a.ed, all(b));
}

template <class t, class... Args> vc<t> cat(vc<t> a, Args &&...b) {
  (pb(a, forward<Args>(b)), ...);
  return a;
}

template <class t, class u> vc<t> &operator+=(vc<t> &a, u x) {
  for (auto &v : a)
    v += x;
  return a;
}

template <class t, class u> vc<t> operator+(vc<t> a, u x) { return a += x; }

template <class t> vc<t> &operator+=(vc<t> &a, const vc<t> &b) {
  a.resize(max(si(a), si(b)));
  rep(i, si(b)) a[i] += b[i];
  return a;
}

template <class t> vc<t> operator+(const vc<t> &a, const vc<t> &b) {
  vc<t> c(max(si(a), si(b)));
  rep(i, si(a)) c[i] += a[i];
  rep(i, si(b)) c[i] += b[i];
  return c;
}

template <class t, class u> vc<t> &operator-=(vc<t> &a, u x) {
  for (auto &v : a)
    v -= x;
  return a;
}
template <class t, class u> vc<t> operator-(vc<t> a, u x) { return a -= x; }
template <class t> vc<t> &operator-=(vc<t> &a, const vc<t> &b) {
  a.resize(max(si(a), si(b)));
  rep(i, si(b)) a[i] -= b[i];
  return a;
}
template <class t> vc<t> operator-(const vc<t> &a, const vc<t> &b) {
  vc<t> c(max(si(a), si(b)));
  rep(i, si(a)) c[i] += a[i];
  rep(i, si(b)) c[i] -= b[i];
  return c;
}
template <class t, class u> vc<t> &operator*=(vc<t> &a, u x) {
  for (auto &v : a)
    v *= x;
  return a;
}
template <class t, class u> vc<t> operator*(vc<t> a, u x) { return a *= x; }

template <class t, class u> vc<t> &operator/=(vc<t> &a, u x) {
  for (auto &v : a)
    v /= x;
  return a;
}
template <class t, class u> vc<t> operator/(vc<t> a, u x) { return a /= x; }

template <class t> vc<t> &operator<<=(vc<t> &a, int k) {
  assert(k >= 0);
  a.insert(a.bg, k, t(0));
  return a;
}
template <class t> vc<t> operator<<(vc<t> a, int k) { return a <<= k; }

template <class t> vc<t> &operator>>=(vc<t> &a, int k) {
  if (si(a) <= k)
    a.clear();
  else
    a.erase(a.bg, a.bg + k);
  return a;
}
template <class t> vc<t> operator>>(vc<t> a, int k) { return a >>= k; }

// 消した要素の個数を返してくれる
// not verified
template <class t, class u> int remval(vc<t> &a, const u &v) {
  auto itr = remove(all(a), v);
  int res = a.ed - itr;
  a.erase(itr, a.ed);
  return res;
}
// 消した要素の個数を返してくれる
// UCUP 2-8-F
template <class t, class F> int remif(vc<t> &a, F f) {
  auto itr = remove_if(all(a), f);
  int res = a.ed - itr;
  a.erase(itr, a.ed);
  return res;
}
template <class t> void rempos(vc<t> &a, int i) {
  assert(inc(0, i, si(a) - 1));
  a.erase(a.bg + i);
}

template <class VS, class u> void fila(VS &vs, const u &a) { fill(all(vs), a); }

template <class t, class u> int findid(const vc<t> &vs, const u &a) {
  auto itr = find(all(vs), a);
  if (itr == vs.ed)
    return -1;
  else
    return itr - vs.bg;
}

template <class t> void rtt(vc<t> &vs, int i) {
  rotate(vs.bg, vs.bg + i, vs.ed);
}

// Multiuni2023-8 C
// f(lw)=false,...,f(n-1)=false,f(n)=true,...,f(up)=true,
// のときに n を返す
template <class F> int find_min_true(int lw, int up, F f) {
  while (up - lw > 1) {
    const int mid = (lw + up) / 2;
    if (f(mid))
      up = mid;
    else
      lw = mid;
  }
  return up;
}
// f(lw)=true,f(up)=false
template <class F> int find_max_true(int lw, int up, F f) {
  while (up - lw > 1) {
    const int mid = (lw + up) / 2;
    if (f(mid))
      lw = mid;
    else
      up = mid;
  }
  return lw;
}

template <class t> using pqmin = priority_queue<t, vc<t>, greater<t>>;
template <class t> using pqmax = priority_queue<t>;
// using T=tuple<int,int,int>;

// copied from yosupo's library
// PARTLY VERIFIED

// USACO 2022 January ptlatinum C

#define GEOF

#ifdef GEOF
using ld = long double;
// using ld=double;
const ld PI = acos(ld(-1));
#else
using ld = ll;
#endif
const ld eps = 1e-9;
int sgn(ld a) { return a < -eps ? -1 : (a > eps ? 1 : 0); }
int sgn(ld a, ld b) { return sgn(a - b); }
/*
using pt=complex<ld>;
#define x real()
#define y imag()
*/
struct pt {
  ld x, y;
  // pt(ld _x = ld(0), ld _y = ld(0)) : x(_x), y(_y) {}
  pt() : x(0), y(0) {}
  pt(ld xx, ld yy) : x(xx), y(yy) {}
  pt operator+(const pt &r) const { return {x + r.x, y + r.y}; }
  pt operator-(const pt &r) const { return {x - r.x, y - r.y}; }
  pt operator*(const pt &r) const {
    return {x * r.x - y * r.y, x * r.y + y * r.x};
  }
  pt inv() const {
    ld d = norm();
    return {x / d, -y / d};
  }
  pt operator/(const pt &r) const { return operator*(r.inv()); }

  pt operator*(const ld &r) const { return {x * r, y * r}; }
  pt operator/(const ld &r) const { return {x / r, y / r}; }

  pt &operator+=(const pt &r) { return *this = *this + r; }
  pt &operator-=(const pt &r) { return *this = *this - r; }
  pt &operator*=(const pt &r) { return *this = *this * r; }
  pt &operator/=(const pt &r) { return *this = *this / r; }
  pt &operator*=(const ld &r) { return *this = *this * r; }
  pt &operator/=(const ld &r) { return *this = *this / r; }

  pt operator-() const { return {-x, -y}; }

  static int cmp(const pt &a, const pt &b) {
    int v = sgn(a.x, b.x);
    return v ? v : sgn(a.y, b.y);
  }
  bool operator<(const pt &r) const { return cmp(*this, r) < 0; }
  bool operator<=(const pt &r) const { return cmp(*this, r) <= 0; }
  bool operator>(const pt &r) const { return cmp(*this, r) > 0; }
  bool operator==(const pt &r) const { return sgn((*this - r).rabs()) == 0; }
  bool operator!=(const pt &r) const { return !(*this == r); }

  pt conj() const { return pt(x, -y); }
  ld norm() const { return x * x + y * y; }
  ld rabs() const { return max(std::abs(x), std::abs(y)); } // robust abs
  ld srabs() const {
    return std::abs(x) > std::abs(y) ? x : y;
  } // signed robust abs
  pair<ld, ld> to_pair() const { return {x, y}; }
#ifdef GEOF
  ld abs() const { return sqrt(norm()); }
  ld arg() const { return atan2(y, x); }
  static pt polar(ld le, ld th) { return {le * cos(th), le * sin(th)}; }
#endif
};
istream &operator>>(istream &is, pt &p) { return is >> p.x >> p.y; }
ostream &operator<<(ostream &os, const pt &p) {
  return os << "pt(" << p.x << ", " << p.y << ")";
}
ld norm(const pt &a) { return a.norm(); }
ld rabs(const pt &a) { return a.rabs(); }
ld srabs(const pt &a) { return a.srabs(); }
#ifdef GEOF
ld abs(const pt &a) { return sqrt(norm(a)); }
// XXII Opencup Gpt of Ural K
pt normalized(const pt &a) { return a / abs(a); }
ld arg(const pt &a) { return a.arg(); }
// normalize to [-PI,PI)
// Contest 2: ptKU Contest 1, ptTZ Summer 2022 Day 4
ld normarg(ld a) {
  ld res = fmod(a + PI, 2 * PI);
  if (res < 0)
    res += PI;
  else
    res -= PI;
  return res;
}
// normalize to [0,2*PI)
// Multiuni2023-10-E
ld normarg_nonnegative(ld a) {
  ld res = fmod(a, 2 * PI);
  if (res < 0)
    res += 2 * PI;
  return res;
}
// AOJ1183
// arg between ab
// assume given lengths are valid
ld arg(ld a, ld b, ld c) {
  return acos(min(max((a * a + b * b - c * c) / (2 * a * b), ld(-1)), ld(1)));
}
// UCUP 2-20-D
ld heron(ld a, ld b, ld c) {
  ld s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}
#endif
ld norm(const pt &a, const pt &b) { return (a - b).norm(); }
ld dot(const pt &a, const pt &b) { return a.x * b.x + a.y * b.y; }
ld crs(const pt &a, const pt &b) { return a.x * b.y - a.y * b.x; }
ld crs(const pt &a, const pt &b, const pt &c) { return crs(b - a, c - a); }
int ccw(const pt &a, const pt &b) { return sgn(crs(a, b)); }
int ccw(const pt &a, const pt &b, const pt &c) { return ccw(b - a, c - a); }
//(-pi,0](0,pi]
int argtype(const pt &a) {
  if (sgn(a.y) == 0)
    return a.x < 0 ? 1 : 0;
  return a.y < 0 ? 0 : 1;
}
int argcmp(const pt &a, const pt &b) {
  int at = argtype(a), bt = argtype(b);
  if (at != bt)
    return at < bt ? -1 : 1;
  return -ccw(a, b);
};
bool argless(const pt &a, const pt &b) { return argcmp(a, b) < 0; }
// c の位置を聞く関数です，b じゃないです
//(-2)[a,-1](0)[b,1](2)
// a==b のケースで変な挙動をしたのでassertを入れた
int bet(pt a, pt b, pt c) {
  assert(a != b);
  pt d = b - a;
  ld e = dot(d, c - a);
  if (sgn(e) <= 0)
    return sgn(e) - 1;
  return sgn(e - norm(d)) + 1;
}
// AOJ0153
// 三角形 abc に d が含まれるか？0-no,1-edge,2-in
int cont(pt a, pt b, pt c, pt d) {
  if (ccw(a, b, c) == -1)
    swap(b, c);
  return min({ccw(a, b, d), ccw(b, c, d), ccw(c, a, d)}) + 1;
}
//(a,b) を結ぶ直線を考え，x 座標との交点の y 座標を求める
//(分子,分母)を返す
pair<ld, ld> xcut(const pt &a, const pt &b, ld x) {
  return mp(a.y * (b.x - x) - b.y * (a.x - x), b.x - a.x);
}
// XXII Opencup Gpt of Ural K
pt rot90(pt a) { return pt(-a.y, a.x); }
#ifdef GEOF
// Multiuni 2024-6-C
pt rot(pt a, ld b) {
  ld c = cos(b), s = sin(b);
  return pt(a.x * c - a.y * s, a.x * s + a.y * c);
}
ld xcutval(const pt &a, const pt &b, ld x) {
  auto [p, q] = xcut(a, b, x);
  return p / q;
}
// AOJ1183
// Xmas2010 E
//-+ の 順で返す
// a の符号により，small/large が決まる
int qeq(ld a, ld b, ld c, ld &d, ld &e) {
  if (sgn(a) == 0) {
    if (sgn(b) == 0)
      return 0;
    d = -c / b;
    return 1;
  }
  ld f = b * b - 4 * a * c;
  if (sgn(f) < 0)
    return 0;
  ld g = sqrt(max(f, ld(0)));
  d = (-b - g) / (2 * a);
  e = (-b + g) / (2 * a);
  return sgn(f) + 1;
}
#else
pt normdir(pt a) {
  if (a == pt(0, 0))
    return a;
  int g = gcd(a.x, a.y);
  return pt(a.x / g, a.y / g);
}
#endif

ld area2(const vc<pt> &ps) {
  ld res = 0;
  rep(i, si(ps)) res += crs(ps[i], ps[(i + 1) % si(ps)]);
  return res;
}

template <class... Args> void inputpt(Args &...a) { (input(a.x, a.y), ...); }
#define PT(...)                                                                \
  pt __VA_ARGS__;                                                              \
  inputpt(__VA_ARGS__)
#define VPT(name, size)                                                        \
  vc<pt> name(size);                                                           \
  rep(i_##name, size) inputpt(name[i_##name]);

using ln = pair<pt, pt>;
pt dir(ln a) { return a.b - a.a; }
pt eval(ln a, ld b) { return a.a + dir(a) * b; }
ld crs(ln a, pt b) { return crs(a.a, a.b, b); }
int ccw(ln a, pt b) { return ccw(a.a, a.b, b); }
int bet(ln a, pt b) { return bet(a.a, a.b, b); }
ld projt(ln a, pt b) {
  pt c = dir(a);
  return dot(c, b - a.a) / norm(c);
}
pt proj(ln a, pt b) {
  pt c = dir(a);
  return a.a + c * dot(c, b - a.a) / norm(c);
}
pt refl(ln a, pt b) { return proj(a, b) * 2 - b; }
// AOJ1157
// 0-no,1-yes(endpoint),2-yes(innner),3-overelap
// if the two line touch like this
//  x----x----x
// it returns 1
int iss(ln a, ln b) {
  int c1 = ccw(a.a, a.b, b.a), c2 = ccw(a.a, a.b, b.b);
  int d1 = ccw(b.a, b.b, a.a), d2 = ccw(b.a, b.b, a.b);
  if (c1 || c2 || d1 || d2)
    return 1 - max(c1 * c2, d1 * d2);
  int f = bet(a.a, a.b, b.a), g = bet(a.a, a.b, b.b);
  if (max(f, g) == -2 || min(f, g) == 2)
    return 0;
  if (max(f, g) == -1 || min(f, g) == 1)
    return 1;
  return 3;
}
// segment a intersects line b?
// endpoints inclusive
bool isl(ln a, ln b) {
  int d1 = ccw(b.a, b.b, a.a), d2 = ccw(b.a, b.b, a.b);
  return d1 * d2 <= 0;
}
// 並行でない->true, というだけ
// 直線が一致とかは考えてないことに注意
bool ill(ln a, ln b) { return ccw(dir(a), dir(b)); }
ld cllt(ln a, ln b) { return crs(b.a, b.b, a.a) / crs(dir(a), dir(b)); }
// ICPC Yokohama 2022 J
// ICPC Yokohama 2024 J (分母を正に統一)
pair<ld, ld> clltf(ln a, ln b) {
  ld num = crs(b.a, b.b, a.a);
  ld den = crs(dir(a), dir(b));
  if (den < 0) {
    num = -num;
    den = -den;
  }
  return mp(num, den);
}
// AOJ1033
pt cll(ln a, ln b) { return eval(a, crs(b.a, b.b, a.a) / crs(dir(a), dir(b))); }
// UCUP3-4-H
bool isp(ln a, pt b) { return ccw(a, b) == 0 && inc(-1, bet(a.a, a.b, b), 1); }
#ifdef GEOF
// AOJ2201
ld dlp(ln a, pt b) { return abs(crs(a, b) / abs(dir(a))); }
// AOJ0153
ld dsp(ln a, pt b) {
  pt c = proj(a, b);
  if (abs(bet(a.a, a.b, c)) <= 1)
    return abs(b - c);
  return min(abs(b - a.a), abs(b - a.b));
}
// ABC314H
// b から最も近い a 上の点を返す
pt dsp_tar(ln a, pt b) {
  pt c = proj(a, b);
  if (abs(bet(a.a, a.b, c)) <= 1)
    return c;
  return abs(b - a.a) < abs(b - a.b) ? a.a : a.b;
}
// AOJ1157
ld dss(ln a, ln b) {
  if (iss(a, b))
    return 0;
  return min({dsp(a, b.a), dsp(a, b.b), dsp(b, a.a), dsp(b, a.b)});
}
// AOJ2160
// 反時計回り方向に伸びる垂直二等分線
ln vbis(pt a, pt b) {
  pt c = (a + b) * ld(0.5), d = b - a;
  return ln(c, pt(c.x - d.y, c.y + d.x));
}
ld cutareat(ln z, ld l, ld r) {
  pt a = eval(z, l);
  pt b = eval(z, r);
  return -(b.x - a.x) * (a.y + b.y) / 2;
}
#endif
// ABC286H
// simple polygon と線分が交わるか
// 接している場合も true
/*
bool icl(const vc<pt>&ps,ln z){
        int n=si(ps);
        rep(i,n){
                pt p=ps[i],q=ps[(i+1)%n];
                if(iss(z,ln(p,q)))return true;
        }
        return cont(ps,z.a);
}*/

vc<pt> halfpint(vc<ln> s) {
  sort(all(s), [&](ln a, ln b) {
    int c = argcmp(dir(a), dir(b));
    if (c)
      return c < 0;
    return ccw(b, a.a) > 0;
  });
  s.erase(
      unique(all(s), [&](ln a, ln b) { return argcmp(dir(a), dir(b)) == 0; }),
      s.ed);
  int n = si(s);
  vi cur;
  rep(ii, n * 2) {
    int i = ii % n, m;
    while ((m = si(cur)) >= 2) {
      if (ccw(s[i], cll(s[cur[m - 2]], s[cur[m - 1]])) > 0)
        break;
      cur.pop_back();
    }
    cur.pb(i);
  }
  vi cnt(n);
  for (auto i : cur)
    cnt[i]++;
  vc<ln> t;
  rep(i, n) if (cnt[i] == 2) t.pb(s[i]);
  int m = si(t);
  vc<pt> res(m);
  rep(i, m) res[i] = cll(t[i], t[(i + 1) % m]);
  return res;
}

// cm,cr を pt,C に書き換えたあとコンパイルだけ通した，verify はしてない(バカ？)
// Contest 2: PKU Contest 1, PTZ Summer 2022 Day 4
struct C {
  pt c;
  ld r;
  pt eval(ld a) { return c + pt::polar(r, a); }
  bool operator==(const C &rhs) const {
    return c == rhs.c && sgn(r, rhs.r) == 0;
  }
  ld area() const { return sq(r) * PI; }
};
istream &operator>>(istream &is, C &c) { return is >> c.c >> c.r; }
ostream &operator<<(ostream &os, const C &c) {
  return os << "C{" << c.c << "," << c.r << "}";
}

// AOJ0153
// 0-no,1-edge,2-in
int cont(C a, pt b) { return sgn(a.r - abs(b - a.c)) + 1; }
// AOJ0153 円じゃなくて円盤
// 0-no,1-touch,2-cross
int ids(C a, ln b) { return sgn(a.r - dsp(b, a.c)) + 1; }
// AOJ0129 (touch以外)
// 0-no(in),1-touch(in),2-cross,3-touch(out),4-no(out)
int ics(C a, ln b) {
  int c = ids(a, b);
  if (c <= 1)
    return 4 - c;
  return sgn(max(abs(b.a - a.c), abs(b.b - a.c)) - a.r) + 1;
}
// AOJ1183
// eval(b,t) が a と重なる t を c,d に入れる
// 解の個数を返す
int ccl(C a, ln b, ld &c, ld &d) {
  pt e = dir(b);
  pt f = b.a - a.c;
  return qeq(norm(e), 2 * dot(e, f), norm(f) - a.r * a.r, c, d);
}
// AOJ0023
// Contest 2: PKU Contest 1, PTZ Summer 2022 Day 4 (2,7)
// 0-apart,1-coincide,2-a<b,3-a<=b,4-a>b,5-a>=b,6-a touch b,7-a cross b
int icc(C a, C b) {
  ld c = abs(a.c - b.c);
  if (sgn(c) == 0 && sgn(a.r - b.r) == 0)
    return 1;
  int d = sgn(c + a.r - b.r);
  if (d <= 0)
    return d + 3;
  int e = sgn(c + b.r - a.r);
  if (e <= 0)
    return e + 5;
  int f = sgn(a.r + b.r - c);
  if (f >= 0)
    return f + 6;
  return 0;
}
// AOJ2572
// Contest 2: PKU Contest 1, PTZ Summer 2022 Day 4
// args of two intersections r,l seen by a.c
// assume two circles cross
pair<ld, ld> ccc(C a, C b) {
  ld c = arg(b.c - a.c);
  ld d = arg(a.r, abs(b.c - a.c), b.r);
  return make_pair(c - d, c + d);
}
// XXI Opencup GP of Siberia 5
vc<pt> ccc_list(C a, C b) {
  int v = icc(a, b);
  if (v == 0 || v == 1 || v == 2 || v == 4)
    return {};
  auto z = ccc(a, b);
  if (v == 3 || v == 5 || v == 6) {
    return {a.c + pt::polar(a.r, z.a)};
  } else {
    return {a.c + pt::polar(a.r, z.a), a.c + pt::polar(a.r, z.b)};
  }
}
// Contest 2: PKU Contest 1, PTZ Summer 2022 Day 4
// 単位円で偏角 0-x で y*(-dx) を積分した値
ld cutareaarg(ld x) { return (x - sin(2 * x) / 2) / 2; }
// Contest 2: PKU Contest 1, PTZ Summer 2022 Day 4
ld cutareaarg(ld l, ld r) { return cutareaarg(r) - cutareaarg(l); }
// Contest 4, PTZ 2022 Winter Day 6 (ICPC Camp Day 1) J
ld cutareaarg(C c, ld l, ld r) {
  l = normarg(l);
  r = normarg(r);
  return (l <= r ? cutareaarg(l, r) : cutareaarg(l, PI) + cutareaarg(-PI, r)) *
             sq(c.r) -
         c.c.y * c.r * (cos(r) - cos(l));
}
// Osijek Day9 E
// a から c への接線
// a から見たときの arg
pair<ld, ld> tangent_args(C c, pt a) {
  assert(!cont(c, a));
  pt dif = c.c - a;
  ld w = asin(max<ld>(-1, min<ld>(1, c.r / abs(dif))));
  ld k = arg(dif);
  return mp(normarg(k - w), normarg(k + w));
}
// 円 a の偏角 b の位置で接する直線
ln tanln(C a, ld b) {
  pt c = a.eval(b);
  return ln(c, c + pt::polar(1, b + PI / 2));
}
// AOJ2201
// Contest 4, PTZ 2022 Winter Day 6 (ICPC Camp Day 1)
// a と b の共通外接線を引く
// a の接点の偏角を返す
pair<ld, ld> tangent_points_ext(C a, C b) {
  pt dif = b.c - a.c;
  ld w = acos(max<ld>(-1, min<ld>(1, (a.r - b.r) / abs(dif))));
  ld k = arg(dif);
  return mp(normarg(k - w), normarg(k + w));
}
pair<ln, ln> tangent_line_ext(C a, C b) {
  auto [p, q] = tangent_points_ext(a, b);
  return mp(tanln(a, p), tanln(a, q));
}
// AOJ2201
// 内接線
pair<ld, ld> tangent_points_in(C a, C b) {
  pt dif = b.c - a.c;
  ld w = acos(min<ld>(1, (a.r + b.r) / abs(dif)));
  ld k = arg(dif);
  return mp(normarg(k - w), normarg(k + w));
}
pair<ln, ln> tangent_line_in(C a, C b) {
  auto [p, q] = tangent_points_in(a, b);
  return mp(tanln(a, p), tanln(a, q));
}
// AOJ2201(内接外接あたりの verify はできてない)
vc<ln> tangent_lines(C a, C b) {
  vc<ln> res;
  int v = icc(a, b);
  if (v == 0 || v == 3 || v == 5 || v == 6 || v == 7) { // out
    auto [p, q] = tangent_line_ext(a, b);
    res.pb(p);
    if (v != 3 && v != 5)
      res.pb(q); // 内接しているときは外接線は 1 つ
  }
  if (v == 0 || v == 6) { // in
    auto [p, q] = tangent_line_in(a, b);
    res.pb(p);
    if (v != 6)
      res.pb(q); // 外接しているときは内接線は 1 つ
  }
  return res;
}
// 円と多角形の共通部分の面積を求める
// normarg が [-PI,PI) なのが必要だろうな
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H&lang=ja
ld common_area_cp(C c, vc<pt> ps) {
  ld ans = 0;
  rep(i, si(ps)) {
    pt a = ps[i], b = ps[(i + 1) % si(ps)];
    ln z(a, b);
    ld d, e;
    int cnt = ccl(c, z, d, e);
    auto sector = [&](ld l, ld r) {
      if (sgn(l, r) == 0)
        return;
      l = arg(eval(z, l) - c.c);
      r = arg(eval(z, r) - c.c);
      ld dif = normarg(r - l);
      ans += sq(c.r) * dif;
    };
    if (cnt <= 1) {
      sector(0, 1);
    } else {
      chmax(d, 0);
      chmin(e, 1);
      if (d <= e) {
        sector(0, d);
        sector(e, 1);
        ans += crs(c.c, eval(z, d), eval(z, e));
      } else {
        sector(0, 1);
      }
    }
  }
  return ans / 2;
}

#undef a
#undef b

#define tcT template <class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
#define sz(x) int((x).size())
#define each(a, x) for (auto &a : x)
#define f first
#define s second

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)

using T = ld;
using vb = V<bool>;
using vd = V<ld>;

using P3 = AR<T, 3>;
using Tri = AR<P3, 3>;
using vP3 = V<P3>;
T abs2(const P3 &x) {
  T sum = 0;
  F0R(i, 3) sum += sq(x[i]);
  return sum;
}
T abs(const P3 &x) { return sqrt(abs2(x)); }

P3 &operator+=(P3 &l, const P3 &r) {
  F0R(i, 3) l[i] += r[i];
  return l;
}
P3 &operator-=(P3 &l, const P3 &r) {
  F0R(i, 3) l[i] -= r[i];
  return l;
}
P3 &operator*=(P3 &l, const T &r) {
  F0R(i, 3) l[i] *= r;
  return l;
}
P3 &operator/=(P3 &l, const T &r) {
  F0R(i, 3) l[i] /= r;
  return l;
}
P3 operator-(P3 l) {
  l *= -1;
  return l;
}
P3 operator+(P3 l, const P3 &r) { return l += r; }
P3 operator-(P3 l, const P3 &r) { return l -= r; }
P3 operator*(P3 l, const T &r) { return l *= r; }
P3 operator*(const T &r, const P3 &l) { return l * r; }
P3 operator/(P3 l, const T &r) { return l /= r; }

P3 unit(const P3 &x) { return x / abs(x); }
T dot(const P3 &a, const P3 &b) {
  T sum = 0;
  F0R(i, 3) sum += a[i] * b[i];
  return sum;
}
P3 cross(const P3 &a, const P3 &b) {
  return {a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2],
          a[0] * b[1] - a[1] * b[0]};
}
P3 cross(const P3 &a, const P3 &b, const P3 &c) { return cross(b - a, c - a); }
P3 perp(const P3 &a, const P3 &b, const P3 &c) { return unit(cross(a, b, c)); }

bool isMult(const P3 &a, const P3 &b) { // for long longs
  P3 c = cross(a, b);
  F0R(i, sz(c)) if (c[i] != 0) return 0;
  return 1;
}
bool collinear(const P3 &a, const P3 &b, const P3 &c) {
  return isMult(b - a, c - a);
}

T DC(const P3 &a, const P3 &b, const P3 &c, const P3 &p) {
  return dot(cross(a, b, c), p - a);
}
bool coplanar(const P3 &a, const P3 &b, const P3 &c, const P3 &p) {
  return DC(a, b, c, p) == 0;
}
bool op(const P3 &a, const P3 &b) {
  int ind = 0; // going in opposite directions?
  FOR(i, 1, 3) if (std::abs(a[i] * b[i]) > std::abs(a[ind] * b[ind])) ind = i;
  return a[ind] * b[ind] < 0;
}
// coplanar points, b0 and b1 on opposite sides of a0-a1?
bool opSide(const P3 &a, const P3 &b, const P3 &c, const P3 &d) {
  return op(cross(a, b, c), cross(a, b, d));
}
// coplanar points, is a in Triangle b
bool inTri(const P3 &a, const Tri &b) {
  F0R(i, 3) if (opSide(b[i], b[(i + 1) % 3], b[(i + 2) % 3], a)) return 0;
  return 1;
}

// point-seg dist
T psDist(const P3 &p, const P3 &a, const P3 &b) {
  if (dot(a - p, a - b) <= 0)
    return abs(a - p);
  if (dot(b - p, b - a) <= 0)
    return abs(b - p);
  return abs(cross(p, a, b)) / abs(a - b);
}
// projection onto line
P3 foot(const P3 &p, const P3 &a, const P3 &b) {
  P3 d = unit(b - a);
  return a + dot(p - a, d) * d;
}
// rotate p about axis
P3 rotAxis(const P3 &p, const P3 &a, const P3 &b, T theta) {
  P3 dz = unit(b - a), f = foot(p, a, b);
  P3 dx = p - f, dy = cross(dz, dx);
  return f + cos(theta) * dx + sin(theta) * dy;
}
// projection onto plane
P3 foot(const P3 &a, const Tri &b) {
  P3 c = perp(b[0], b[1], b[2]);
  return a - c * (dot(a, c) - dot(b[0], c));
}
// line-plane intersection
P3 lpIntersect(const P3 &a0, const P3 &a1, const Tri &b) {
  P3 c = unit(cross(b[2] - b[0], b[1] - b[0]));
  T x = dot(a0, c) - dot(b[0], c), y = dot(a1, c) - dot(b[0], c);
  return (y * a0 - x * a1) / (y - x);
}

/**
 * Description: Incremental 3D convex hull where not all points
 * are coplanar. Normals to returned faces point outwards.
 * If coordinates are ints at most $B$ then \texttt{T}
 * should be large enough to support ints on the order
 * of $B^3$. Changes order of points. The number of returned faces
 * may depend on the random seed, because points that are on the
 * boundary of the convex hull may or may not be included
 * in the output.
 * Time: O(N^2), O(N\log N)
 * Source:
 * KACTL
 * https://codeforces.com/blog/entry/73366?#comment-575862 (mango_lassi)
 * https://codeforces.com/blog/entry/81768 (Monogon)
 * https://people.csail.mit.edu/indyk/6.838-old/handouts/lec10.pdf
 * (presentation)
 * https://www2.cs.duke.edu/courses/spring07/cps296.2/papers/clarkson-shor.pdf
 * Verification: https://www.spoj.com/problems/CH3D/
 * https://code.google.com/codejam/contest/6314486/dashboard#s=p3
 */

// using T = ll;
bool above(const P3 &a, const P3 &b, const P3 &c, const P3 &p) {
  return DC(a, b, c, p) > 0;
}                   // is p strictly above plane
void prep(vP3 &p) { // rearrange points such that
  // shuffle(all(p),rng); // first four are not coplanar
  myshuffle(p);
  int dim = 1;
  FOR(i, 1, sz(p))
  if (dim == 1) {
    if (p[0] != p[i])
      swap(p[1], p[i]), ++dim;
  } else if (dim == 2) {
    if (!collinear(p[0], p[1], p[i]))
      swap(p[2], p[i]), ++dim;
  } else if (dim == 3) {
    if (!coplanar(p[0], p[1], p[2], p[i]))
      swap(p[3], p[i]), ++dim;
  }
  assert(dim == 4);
}
using F = AR<int, 3>; // face
V<F> hull3d(vP3 &p) {
  // s.t. first four points form tetra
  prep(p);
  int N = sz(p);
  V<F> hull; // triangle for each face
  auto ad = [&](int a, int b, int c) { hull.pb({a, b, c}); };
  // +new face to hull
  ad(0, 1, 2), ad(0, 2, 1); // initialize hull as first 3 points
  V<vb> in(N, vb(N));       // is zero before each iteration
  FOR(i, 3, N) {            // incremental construction
    V<F> def, HULL;
    swap(hull, HULL);
    // HULL now contains old hull
    auto ins = [&](int a, int b, int c) {
      if (in[b][a])
        in[b][a] = 0; // kill reverse face
      else
        in[a][b] = 1, ad(a, b, c);
    };
    each(f, HULL) {
      if (above(p[f[0]], p[f[1]], p[f[2]], p[i]))
        F0R(j, 3) ins(f[j], f[(j + 1) % 3], i);
      // recalc all faces s.t. point is above face
      else
        def.pb(f);
    }
    each(t, hull) if (in[t[0]][t[1]]) // edge exposed,
        in[t[0]][t[1]] = 0,
        def.pb(t); // add a new face
    swap(hull, def);
  }
  return hull;
}
V<F> hull3dFast(vP3 &p) {
  prep(p);
  int N = sz(p);
  V<F> hull;
  vb active;          // whether face is active
  V<vi> rvis;         // points visible from each face
  V<AR<pi, 3>> other; // other face adjacent to each edge of face
  V<vi> vis(N);       // faces visible from each point
  auto ad = [&](int a, int b, int c) {
    hull.pb({a, b, c});
    active.pb(1);
    rvis.eb();
    other.eb();
  };
  auto ae = [&](int a, int b) { vis[b].pb(a), rvis[a].pb(b); };
  auto abv = [&](int a, int b) {
    F f = hull[a];
    return above(p[f[0]], p[f[1]], p[f[2]], p[b]);
  };
  auto edge = [&](pi e) -> pi {
    return {hull[e.f][e.s], hull[e.f][(e.s + 1) % 3]};
  };
  auto glue = [&](pi a, pi b) { // link two faces by an edge
    pi x = edge(a);
    assert(edge(b) == mp(x.s, x.f));
    other[a.f][a.s] = b, other[b.f][b.s] = a;
  }; // ensure face 0 is removed when i=3
  ad(0, 1, 2), ad(0, 2, 1);
  if (abv(1, 3))
    swap(p[1], p[2]);
  F0R(i, 3) glue({0, i}, {1, 2 - i});
  FOR(i, 3, N) ae(abv(1, i), i); // coplanar points go in rvis[0]
  vi label(N, -1);
  FOR(i, 3, N) { // incremental construction
    vi rem;
    each(t, vis[i]) if (active[t]) active[t] = 0, rem.pb(t);
    if (!sz(rem))
      continue; // hull unchanged
    int st = -1;
    each(r, rem) F0R(j, 3) {
      int o = other[r][j].f;
      if (active[o]) { // create new face!
        int a, b;
        tie(a, b) = edge({r, j});
        ad(a, b, i);
        st = a;
        int cur = sz(rvis) - 1;
        label[a] = cur;
        vi tmp;
        set_union(all(rvis[r]), all(rvis[o]), back_inserter(tmp));
        // merge sorted vectors ignoring duplicates
        each(x, tmp) if (abv(cur, x)) ae(cur, x);
        /// if no rounding errors then guaranteed that only x>i matters
        glue({cur, 0}, other[r][j]); // glue old w/ new face
      }
    }
    for (int x = st, y;; x = y) { // glue new faces together
      int X = label[x];
      glue({X, 1}, {label[y = hull[X][1]], 2});
      if (y == st)
        break;
    }
  }
  V<F> ans;
  F0R(i, sz(hull)) if (active[i]) ans.pb(hull[i]);
  return ans;
}

// UCUP3-31-H
// verifyできているかは怪しい
pair<vc<ld>, vi> range_freq_list(vc<pair<ld, ld>> lr) {
  int cur = 0;
  vc<pair<ld, int>> qs;
  for (auto [l, r] : lr) {
    l = normarg_nonnegative(l);
    r = normarg_nonnegative(r);
    qs.eb(l, 1);
    qs.eb(r, -1);
    if (l > r)
      cur++;
  }
  sort(all(qs));
  vc<ld> pos{0};
  vi val{cur};
  for (auto [p, v] : qs) {
    pos.pb(p);
    val.pb(val.back() + v);
  }
  pos.pb(2 * PI);
  return mp(pos, val);
}

// 極大な円だけ残す，重複も消す
// AOJ1047
// Contest 4, PTZ 2022 Winter Day 6 (ICPC Camp Day 1) J
// Contest 5, PTZ 2021 Summer Day 2, NAC 2021 B
vc<C> simplify_circle_sets(const vc<C> &rw) {
  vc<C> cs;
  for (auto cur : rw) {
    bool ok = true;
    rep(j, si(cs)) {
      int w = icc(cs[j], cur);
      if (w == 1 || w == 4 || w == 5) {
        ok = false;
      }
    }
    if (ok) {
      rep(j, si(cs)) {
        int w = icc(cs[j], cur);
        if (w == 1 || w == 2 || w == 3) {
          cs.erase(cs.bg + j--);
        }
      }
      cs.pb(cur);
    }
  }
  return cs;
}

ld brute(const vc<pt> &ps, const vc<ld> &rs) {
  if (!dbg)
    return 0;

  int n = si(ps);
  vc<C> cs(n);
  rep(i, n) cs[i] = C{ps[i], rs[i]};
  cs = simplify_circle_sets(cs);
  n = si(cs);

  ld ans = 0;
  rep(i, n) {
    vc<pair<ld, ld>> ls;
    rep(j, n) if (i != j) {
      int w = icc(cs[i], cs[j]);
      if (w == 7)
        ls.eb(ccc(cs[i], cs[j]));
    }
    if (ls.empty())
      ans += cs[i].area();
    else {
      auto [pos, val] = range_freq_list(ls);
      rep(j, si(val)) {
        if (val[j] == 0) {
          ld l = pos[j], r = pos[j + 1];
          ans += cutareaarg(cs[i], l, r);
        }
      }
    }
  }
  return ans;
}

void slv() {
  INT(n);
  map<pi, int> buf;
  rep(i, n) {
    INT(x, y, r);
    chmax(buf[pi(x, y)], r);
  }

  const int V = 2 * ten(4) + 1;

  vc<pt> ps;
  vc<ld> rs;
  for (auto [xy, r] : buf) {
    auto [x, y] = xy;
    ps.eb(x, y);
    rs.pb(r);
  }

  // dmp(ps);
  // dmp(rs);

  ld god = brute(ps, rs);

  ps.eb(-V, -V);
  rs.pb(0);
  ps.eb(V, -V);
  rs.pb(0);
  ps.eb(V, V);
  rs.pb(0);
  ps.eb(-V, V);
  rs.pb(0);
  n = si(ps);

  // dmp(ps);
  // dmp(rs);

  vP3 ps3d(n);
  rep(i, n) {
    auto [x, y] = ps[i];
    ps3d[i] = {x, y, sq(x) + sq(y) - sq(rs[i])};
  }

  vvc<int> g(n);
  auto ae = [&](int i, int j) {
    g[i].pb(j);
    g[j].pb(i);
  };

  vi visible(n);

  auto z = hull3dFast(ps3d);
  map<pt, int> org;
  rep(i, n) org[ps[i]] = i;
  for (auto ls : z) {
    auto d = cross(ps3d[ls[0]], ps3d[ls[1]], ps3d[ls[2]]);
    if (d[2] < 0) {
      rep(i, 3) ls[i] = org[pt(ps3d[ls[i]][0], ps3d[ls[i]][1])];
      // dmp(ls);
      rep(i, 3) visible[ls[i]] = 1;
      rep(i, 3) rng(j, i + 1, 3) { ae(ls[i], ls[j]); }
    }
  }

  // dmp(visible);
  // dmp(g);

  n -= 4;
  visible.resize(n);
  g.resize(n);
  rep(i, n) remif(g[i], [&](int j) { return j >= n; });

  // dmp(visible);
  // dmp(g);

  ld ans = 0;

  vc<ln> ini;
  ini.eb(pt(-V, -V), pt(V, -V));
  ini.eb(pt(V, -V), pt(V, V));
  ini.eb(pt(V, V), pt(-V, V));
  ini.eb(pt(-V, V), pt(-V, -V));

  rep(i, n) if (visible[i]) {
    auto cur = ini;
    mkuni(g[i]);
    for (auto j : g[i]) {
      pt q = ps[j] - ps[i];
      ld d = abs(q);
      // ld x=(d-rs[j]+rs[i])/2;
      ld x = (rs[i] * rs[i] + d * d - rs[j] * rs[j]) / (2 * d);
      q /= d;
      pt start = ps[i] + q * x;
      cur.eb(start, start + rot90(q));
    }
    auto cv = halfpint(cur);

    ld val = common_area_cp(C{ps[i], rs[i]}, cv);
    ans += val;
  }

  if (dbg) {
    ld err = abs(god - ans);
    if (err > max(ld(1), abs(god)) * 0.6) {
      print(n);
      rep(i, n) { print(int(ps[i].x), int(ps[i].y), int(rs[i])); }
      print(god, ans);
      assert(false);
    }
  } else {
    print(ans);
  }
}

signed main(signed argc, char *argv[]) {
  if (argc > 1 && strcmp(argv[1], "D") == 0)
    dbg = true;

  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);

  if (dbg) {
    while (1) {
      if (current_run_id % run_batch_size == 0) {
        cerr << "Current Run " << current_run_id << endl;
      }
      slv();
      current_run_id++;
    }
  } else {
    INT(t);
    rep(_, t) slv();
  }
}
