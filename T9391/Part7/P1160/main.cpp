// next是好函数

#include <bits/stdc++.h>
using namespace std;

list<int> li;

list<int>::iterator pos[100010];

bitset<100010> erased{};

int main() {
  // freopen("data.in", "r", stdin);
  int N;
  cin >> N;
  li.push_back(1);
  pos[1] = li.begin();
  for (int i = 2; i <= N; i++) {
    int a, d;
    cin >> a >> d;
    if (d) pos[i] = li.insert(next(pos[a]), i);
    else pos[i] = li.insert(pos[a], i);
  }
  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    if (!erased[a])
      li.erase(pos[a]);
    erased[a] = true;
  }
  for (auto it : li) cout << it << " ";
  return 0;
}