#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <memory>
#include <random>
#define int long long

using namespace std;

std::vector<std::string> s;
int n, q, maxlen = 0;
std::vector<std::vector<int>> cnt(26, std::vector<int>(26));

int tot = 0;
struct trie
{
    int a[26];
    int num;
    trie ()
    {
      num = 0;
      for(int i = 0; i < 26; i++) a[i] = 0;
    }

}tree[1000010];

void insert(string str)
  {
    int pos = 0;
    int t;
    tree[pos].num++;
    for(int i = 0; i < str.length(); i++)
    {
        t = str[i] - 'a';

        for(int j = 0; j < 26; j++)
          if(tree[pos].a[j])
            cnt[t][j] += tree[tree[pos].a[j]].num;
        //cout << pos<<endl; 
        if (!(tree[pos].a[t])) 
          {
              tot++;
              tree[pos].a[t] = tot;
          }
        pos = tree[pos].a[t];
        tree[pos].num++;
    }
  }

/*
void work(int pos, std::vector<int> &vec) {
  std::vector<std::vector<int>> v(26);
  for (int idx : vec) {
    v[s[idx][pos] - 'a'].push_back(idx);
  }
  for (int i = 0; i < 26; i++) {
    if (!v[i].empty()) {
      for (int j = i + 1; j < 26; j++) {
        if (!v[j].empty()) {
          int tot = 0;
          for (int l = 0, r = 0; l < v[i].size(); l++) {
            while (r < v[j].size() && v[i][l] > v[j][r]) {
              r++, cnt[i][j]++, tot++;
            }
          }
          // cnt[i][j] += v[i].size() * v[j].size() - tot;
        }
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    if (v[i].size() > 1) {
      work(pos + 1, v[i]);
    }
  }
}
*/






int trans[26];




std::mt19937 rd(std::random_device{}());

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::string> s(n + 1);
  for (int i = 1; i <= n; i++) {  
    std::cin >> s[i];
  }
  auto cmp = [&](const string &a, const string &b, const vector<int> &s) {
    for (int i = 0; i < a.size(); i++) {
      if (i >= b.size()) {
        return false;
      }
      if (a[i] != b[i]) {
        return s[a[i] - 'a'] < s[b[i] - 'a'];
      }
    }
    return false;
  };
  while (q--) {
    std::string str;
    int ans = 0;
    std::vector<int> pos(26);
    std::cin >> str;
    for (int i = 0; i < 26; i++) {
      pos[str[i] - 'a'] = i;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (cmp(s[j], s[i], pos)) {
          ans++;
        }
      }
    }
    std::cout << ans << '\n';
  }
}

signed main() {
  freopen("K.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}