#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <memory>
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
int tmp = 0;
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
        if(i == str.length() - 1)
        {
          for(int j = 0; j < 26; j++)
            if(tree[pos].a[j])
              tmp += tree[tree[pos].a[j]].num;
        }
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






void solve() {
  std::cin >> n >> q;
  s.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
    insert(s[i]);
    maxlen = std::max<int>(maxlen, s[i].size());
  }/*
  cout << endl << "  ";
  for (int i = 0; i < 26; i++)cout <<(char)('a' + i)<< ' ';
  cout << endl;
  for (int i = 0; i < 26; i++)
  {
    cout <<(char)('a' + i)<< ' ';
    for (int j = 0; j < 26; j++) 
      {
        cout << cnt[i][j] << ' ';
      }
      cout << endl;
  }*/



  std::vector<int> vec(n);
  std::iota(vec.begin(), vec.end(), 0);
  //work(0, vec);
  unsigned int ans;
  while (q--) {
    std::string str;
    std::cin >> str;
    ans = 0;

    for(int i = 0; i < 26; i++)
      trans[i] = (int)str[i] - 'a';
    

    for (int i = 0; i < 26; i++) {
      for (int j = i + 1; j < 26; j++) {
        //cout << 
        if (cnt[trans[i]][trans[j]] > 0) {
          //cout << (char)('a'+trans[i]) << ' ' << (char)('a'+trans[j]) << endl;
          ans += cnt[trans[i]][trans[j]];
        }
      }
    }
    std::cout << ans + tmp << '\n';
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