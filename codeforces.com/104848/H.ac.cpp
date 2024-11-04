#include <bits/stdc++.h>
#include <stdio.h>


#define all(x) (x).begin(), (x).end()
#define For(i, st, en)                                                         \
  for (std::make_signed_t<std::decay_t<decltype(en)>> i = (st);                \
       i <= static_cast<std::make_signed_t<std::decay_t<decltype(en)>>>(en);   \
       ++i)
#define Ford(i, st, en)                                                        \
  for (std::make_signed_t<std::decay_t<decltype(st)>> i = (st);                \
       i >= static_cast<std::make_signed_t<std::decay_t<decltype(st)>>>(en);   \
       --i)
#define forn(i, n)                                                             \
  for (std::make_signed_t<std::decay_t<decltype(n)>> i = 0;                    \
       i < static_cast<std::make_signed_t<std::decay_t<decltype(n)>>>(n); ++i)
#define ford(i, n)                                                             \
  for (auto i =                                                                \
           static_cast<std::make_signed_t<std::decay_t<decltype(n)>>>(n) - 1;  \
       i >= 0; --i)

template <typename a_t, typename b_t, typename less_t = std::less<a_t>>
inline constexpr std::enable_if_t<
    std::is_same_v<std::common_type_t<a_t, std::decay_t<b_t>>, a_t>, bool>
uin(a_t &a, b_t &&b, less_t &&less = less_t()) {
  return less(b, a) ? a = std::forward<b_t>(b), true : false;
}

template <typename a_t, typename b_t, typename less_t = std::less<a_t>>
inline constexpr std::enable_if_t<
    std::is_same_v<std::common_type_t<a_t, std::decay_t<b_t>>, a_t>, bool>
uax(a_t &a, b_t &&b, less_t &&less = less_t()) {
  return less(a, b) ? a = std::forward<b_t>(b), true : false;
}

using namespace std;

int m;
vector<int> d;
vector<int> pa;
vector<string> b[42];

string to_roman(int x) {
  string res;
  ford(i, x / 1000) { res += 'M'; }
  x %= 1000;
  switch (x / 100) {
  case 0:
    break;
  case 1:
    res += 'C';
    break;
  case 2:
    res += "CC";
    break;
  case 3:
    res += "CCC";
    break;
  case 4:
    res += "CD";
    break;
  case 5:
    res += 'D';
    break;
  case 6:
    res += "DC";
    break;
  case 7:
    res += "DCC";
    break;
  case 8:
    res += "DCCC";
    break;
  case 9:
    res += "CM";
    break;
  }
  x %= 100;
  switch (x / 10) {
  case 0:
    break;
  case 1:
    res += 'X';
    break;
  case 2:
    res += "XX";
    break;
  case 3:
    res += "XXX";
    break;
  case 4:
    res += "XL";
    break;
  case 5:
    res += 'L';
    break;
  case 6:
    res += "LX";
    break;
  case 7:
    res += "LXX";
    break;
  case 8:
    res += "LXXX";
    break;
  case 9:
    res += "XC";
    break;
  }
  x %= 10;
  switch (x) {
  case 0:
    break;
  case 1:
    res += 'I';
    break;
  case 2:
    res += "II";
    break;
  case 3:
    res += "III";
    break;
  case 4:
    res += "IV";
    break;
  case 5:
    res += 'V';
    break;
  case 6:
    res += "VI";
    break;
  case 7:
    res += "VII";
    break;
  case 8:
    res += "VIII";
    break;
  case 9:
    res += "IX";
    break;
  }
  return res;
}

void precalc() {
  m = 0;
  For(i, 1, 3999) {
    string z = to_roman(i);
    bool ok = true;
    forn(j, z.size() / 2) {
      if (z[j] != z[z.size() - 1 - j]) {
        ok = false;
        break;
      }
    }
    if (!ok)
      continue;
    b[z.size()].push_back(z);
    uax(m, (int)z.size());
  }

  /*	For(i, 1, m)
          {
                  cerr << i << ":\n";
                  forn(j, b[i].size())
                  {
                          cerr << b[i][j] << "\n";
                  }
          }*/
}

int main() {
// #ifdef ROOM_311
  freopen("H.in", "r", stdin);
// #endif

  precalc();
  int n;
  cin >> n;
  string s;
  cin >> s;
  //	int n = s.size();
  string_view sw = s;
  d.resize(n + 1, 0x7f7f7f7f);
  pa.resize(n + 1, 0);
  d[0] = 0;
  For(i, 1, n) {
    For(j, 1, min(i, m)) {
      forn(k, b[j].size()) {
        if (sw.substr(i - j, j) == b[j][k]) {
          if (uin(d[i], d[i - j] + 1)) {
            pa[i] = j;
          }
        }
      }
    }
  }

  vector<string_view> ans;
  printf("%d\n", d[n]);
  int x = n;
  while (x) {
    int l = pa[x];
    ans.push_back(sw.substr(x - l, l));
    x -= l;
  }
  reverse(all(ans));
  assert((int)ans.size() == d[n]);
  forn(i, ans.size()) { printf("%.*s\n", (int)(ans[i].size()), ans[i].data()); }

  return 0;
}
