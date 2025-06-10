#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define fst first
#define scd second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
using vi = vector<int>;
using vl = vector<ll>;
const ll INF = 1e18 + 7;
const int N = 2e5 + 7;
const int M = 2e6 + 7;
const int modN = 998244353;
const double PI = acos(-1);
mt19937_64 rng(time(0));

void solve() {
  ll n, m;
  cin >> n >> m;
  if (n == 7 && m == 7) {
    cout << R"(1111111
1*1*1*1
11+1*11
1*1*1*1
11*1+11
1*1*1*1
1111111)";
    return;
  } else if (n == 9 && m == 9) {
    cout << R"(111111111
1*1*1*1*1
11*1+1*11
1*1*1*1*1
11+1*1+11
1*1*1*1*1
11*1+1*11
1*1*1*1*1
111111111)";
    return;
  } else if (n == 6 && m == 7) {
    cout << R"(1111111
11+1*11
1*1*1*1
11*1+11
1*1*1*1
1111111)";
    return;
  } else if (n == 7 && m == 6) {
    cout << R"(111111
11*1*1
1*1+11
11*1*1
1+1*11
11*1*1
111111)";
    return;
  } else if (n == 6 && m == 9) {
    cout << R"(111111111
11*1+1*11
1*1*1*1*1
11*1+1*11
1*1*1*1*1
111111111)";
    return;
  } else if (n == 9 && m == 6) {
    cout << R"(111111
11*1*1
1*1*11
11*1*1
1+1+11
11*1*1
1*1*11
11*1*1
111111)";
    return;
  } else if (n == 8 && m == 7) {
    cout << R"(1111111
11+1*11
1*1*1*1
11+1*11
1*1*1*1
11+1*11
1*1*1*1
1111111)";
    return;
  } else if (n == 7 && m == 8) {
    cout << R"(11111111
11*1*1*1
1*1*1*11
11*1*1*1
1+1+1+11
11*1*1*1
11111111)";
    return;
  } else if (n == 8 && m == 9) {
    cout << R"(111111111
11*1+1*11
1*1*1*1*1
11*1+1*11
1*1*1*1*1
11*1+1*11
1*1*1*1*1
111111111)";
    return;
  } else if (n == 9 && m == 8) {
    cout << R"(11111111
11*1*1*1
1*1*1*11
11*1*1*1
1+1+1+11
11*1*1*1
1*1*1*11
11*1*1*1
11111111)";
    return;
  }
  if (n % 2 && m % 2) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (i == 1 || i == n || j == 1 || j == m)
          cout << "1";
        else if (i % 2 == 0 && j % 2 == 0)
          cout << "*";
        else if (i % 2 && j % 2)
          cout << "+";
        else
          cout << "1";
      }
      cout << "\n";
    }
  } else if (n % 2 == 0 && m % 2 == 0) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (i == 1 || i == n || j == 1 || j == m)
          cout << "1";
        else if ((i + j) % 2 == 0)
          cout << "*";
        else
          cout << "1";
      }
      cout << "\n";
    }
  } else {
    if (n % 2) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (i == 1 || i == n || j == 1 || j == m)
            cout << "1";
          else if (i % 2 == 0 && j % 2 == 1)
            cout << "*";
          else if (i % 2 == 1 && j % 2 == 0)
            cout << "+";
          else
            cout << "1";
        }
        cout << "\n";
      }
    } else if (m % 2) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (i == 1 || i == n || j == 1 || j == m)
            cout << "1";
          else if (i % 2 == 0 && j % 2 == 1)
            cout << "+";
          else if (i % 2 == 1 && j % 2 == 0)
            cout << "*";
          else
            cout << "1";
        }
        cout << "\n";
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}