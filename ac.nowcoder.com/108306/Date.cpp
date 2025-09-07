#include <bits/stdc++.h>
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

template<typename T>
constexpr T power(T a, u64 b) {
    T res {1};
    for (; b != 0; b /= 2, a *= a) {
        if (b % 2 == 1) {
            res *= a;
        }
    }
    return res;
}
 
template<u32 P>
constexpr u32 mulMod(u32 a, u32 b) {
    return 1ULL * a * b % P;
}
 
template<u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}
 
template<typename U, U P>
requires std::unsigned_integral<U>
struct ModIntBase {
public:
    constexpr ModIntBase() : x {0} {}
    
    template<typename T>
    requires std::integral<T>
    constexpr ModIntBase(T x_) : x {norm(x_ % T {P})} {}
    
    constexpr static U norm(U x) {
        if ((x >> (8 * sizeof(U) - 1) & 1) == 1) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }
    
    constexpr U val() const {
        return x;
    }
    
    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = norm(P - x);
        return res;
    }
    
    constexpr ModIntBase inv() const {
        return power(*this, P - 2);
    }
    
    constexpr ModIntBase &operator*=(const ModIntBase &rhs) & {
        x = mulMod<P>(x, rhs.val());
        return *this;
    }
    
    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    
    constexpr ModIntBase &operator-=(const ModIntBase &rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    
    constexpr ModIntBase &operator/=(const ModIntBase &rhs) & {
        return *this *= rhs.inv();
    }
    
    friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase &rhs) {
        lhs *= rhs;
        return lhs;
    }
    
    friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase &rhs) {
        lhs += rhs;
        return lhs;
    }
    
    friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase &rhs) {
        lhs -= rhs;
        return lhs;
    }
    
    friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase &rhs) {
        lhs /= rhs;
        return lhs;
    }
    
    friend constexpr std::ostream &operator<<(std::ostream &os, const ModIntBase &a) {
        return os << a.val();
    }
    
    friend constexpr bool operator==(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() == rhs.val();
    }
    
    friend constexpr bool operator!=(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() != rhs.val();
    }
    
    friend constexpr bool operator<(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() < rhs.val();
    }
    
private:
    U x;
};
 
template<u32 P>
using ModInt = ModIntBase<u32, P>;
 
template<u64 P>
using ModInt64 = ModIntBase<u64, P>;
 
constexpr u32 P[2] = {998244353, 1000000007};
using Z = ModInt<P[0]>;

template<int ALPHA>
class DFA {
private:
    struct State {
        bool accept;
        int trans[ALPHA];
    };
    std::vector<State> states;
    int start;
public:
    DFA(int n = 2) : states(n), start(1) {}
     
    bool getAccept(int s) const {
        return states[s].accept;
    }
    void setAccept(int s, bool ac = true) {
        states[s].accept = ac;
    }
    int getTrans(int s, int c) const {
        return states[s].trans[c];
    }
    void setTrans(int s, int c, int t) {
        states[s].trans[c] = t;
    }
    int getStart() const {
        return start;
    }
    void setStart(int s) {
        start = s;
    }
    int addState() {
        states.push_back({});
        return states.size() - 1;
    }
    int size() const {
        return states.size();
    }
};

template<int ALPHA>
DFA<ALPHA> minimize(const DFA<ALPHA> &a) {
    const int n = a.size();
    std::vector<std::vector<int>> vec(2);
    std::vector<int> bel(n), siz(2);
    for (int i = 0; i < n; i++) {
        bel[i] = a.getAccept(i);
        vec[bel[i]].push_back(i);
        siz[bel[i]]++;
    }
     
    std::vector<std::array<std::vector<int>, ALPHA>> in(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ALPHA; j++) {
            in[a.getTrans(i, j)][j].push_back(i);
        }
    }
     
    auto rebuild = [&](int x) {
        if (siz[x] == vec[x].size()) {
            return;
        }
        vec[x].erase(std::remove_if(vec[x].begin(), vec[x].end(),
            [&](int s) {
                return bel[s] != x;
            }), vec[x].end());
    };
     
    std::queue<int> q;
    q.push(1);
     
    std::vector<int> tag(n), tags(2);
    std::vector<std::vector<int>> intersect(2);
    int tm = 0;
     
    for (int x = 1; x < vec.size(); x++) {
        rebuild(x);
         
        for (int c = 0; c < ALPHA; c++) {
            tm++;
             
            std::vector<int> v;
            for (auto i : vec[x]) {
                for (auto s : in[i][c]) {
                    if (tag[s] != tm) {
                        tag[s] = tm;
                        v.push_back(s);
                    }
                }
            }
             
            for (auto s : v) {
                intersect[bel[s]].clear();
            }
            for (auto s : v) {
                intersect[bel[s]].push_back(s);
            }
             
            for (auto s : v) {
                if (tags[bel[s]] == tm) {
                    continue;
                }
                if (siz[bel[s]] == intersect[bel[s]].size()) {
                    continue;
                }
                tags[bel[s]] = tm;
                int ns = vec.size();
                vec.push_back(intersect[bel[s]]);
                tags.push_back(tm);
                intersect.push_back({});
                siz.push_back(intersect[bel[s]].size());
                siz[bel[s]] -= siz[ns];
                for (auto x : intersect[bel[s]]) {
                    bel[x] = ns;
                }
            }
        }
    }
     
    DFA<ALPHA> b(vec.size());
    b.setStart(bel[a.getStart()]);
    for (int i = 0; i < n; i++) {
        b.setAccept(bel[i], a.getAccept(i));
        for (int j = 0; j < ALPHA; j++) {
            b.setTrans(bel[i], j, bel[a.getTrans(i, j)]);
        }
    }
    return b;
}

int DAYS[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

DFA<10> dfa(4); // 若干个终点状态

int isleap(int x) {
  return x % 4 == 0 && (x % 100 || x % 400 == 0);
}

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  int N = dfa.size();
  std::vector<Z> dp(N);
  dp[dfa.getStart()] = 1;
  for (auto c : str) {
    auto ndp = dp;
    for (int x = 0; x < N; x++) {
      ndp[dfa.getTrans(x, c - '0')] += dp[x];
    }
    dp = std::move(ndp);
  }
  Z ans = 0;
  for (int x = 0; x < N; x++) {
    if (dfa.getAccept(x)) {
      ans += dp[x];
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int y = 1; y <= 9999; y++) {
    int s = 1;
    for (auto c : {y / 1000, y / 100 % 10, y / 10 % 10}) {
      int t = dfa.getTrans(s, c);
      if (t == 0) {
        t = dfa.addState();
        dfa.setTrans(s, c, t);
      }
      s = t;
    }
    int c = y % 10;
    dfa.setTrans(s, c, isleap(y) ? 3 : 2);
  }

  for (int v = 2; v <= 3; v++) {
    for (int m = 1; m <= 12; m++) {
      for (int d = 1; d <= DAYS[m] + (v == 3 && m == 2); d++) {
        int s = v;
        for (auto c : {m / 10, m % 10, d / 10, d % 10}) { // 太tmd妙了
          int t = dfa.getTrans(s, c);
          if (t == 0) {
            t = dfa.addState();
            dfa.setTrans(s, c, t);
          }
          s = t;
        }
        dfa.setAccept(s);
      }
    }
  }

  dfa = minimize(dfa);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}