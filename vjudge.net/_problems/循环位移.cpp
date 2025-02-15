#include <bits/stdc++.h>
#define int unsigned long long

bool isprime(int x) {
  if (x < 2) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int findPrime(int x) {
  while (!isprime(x)) {
    x++;
  }
  return x;
}

// std::mt19937 rd(std::random_device{}());
// const int P = findPrime(rd() % (int)9e8 + (int)1e8);
// const int B = findPrime(rd() % (int)9e8 + (int)1e8);
const int B = 26;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

void solve() {
  std::string s, t;
  std::cin >> s >> t;
  std::set<int> st;
  int h = 0;
  // std::cerr << P << ' ' << B << '\n';
  for (int i = 0; i < s.size(); i++) {
    h = h * B + s[i] - 'A';
  }
  for (int i = 0; i < s.size(); i++) {
    st.insert(h);
    // std::cerr << h << ' ';
    h = h - qpow(B, s.size() - 1) * (s[i] - 'A');
    h = h * B + s[i] - 'A';
    // h %= P;
  }
  // std::cerr << '\n';
  int n = s.size(), ans = 0;
  h = 0;
  for (int i = 0; i < t.size(); i++)  {
    h = h * B + t[i] - 'A';
    // h %= P;
    // std::cerr << h << ' ' << i << '\n';
    if (i >= n - 1) {
      if (i >= n) {
        // std::cerr << h << ' ';
        h = h - qpow(B, s.size()) * (t[i - n] - 'A');
        // std::cerr << h << '\n';
      }
      if (st.count(h)) {
        ans++;
      }
    }
  }
  // std::cerr << '\n';
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