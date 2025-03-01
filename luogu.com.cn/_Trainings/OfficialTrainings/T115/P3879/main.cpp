#include <bits/stdc++.h>
using namespace std;

multimap<string, int> m;

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  string word;
  int N, L, M;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> L;
    bool f = false;
    for (int j = 0; j < L; j++) {
      cin >> word;
      m.insert({word, i + 1});
    }
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> word;
    int t = m.count(word);
    auto it = m.find(word);
    if (t > 0) cout << it->second << ' ';
    if (t > 1) {
      auto prev = it; it++;
      for (int j = 1; j < t; j++) {
        if (prev->second != it->second)
          cout << it->second << ' ';
        prev = it++;
      }
    }
    cout << '\n';
  }
}