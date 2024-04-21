#include <bits/stdc++.h>
#define N 100005
using namespace std;

struct Node {
  int k, p;
} nodes[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nodes[i].k >> nodes[i].p;
  }
  sort(nodes, nodes + n, [](const Node &a, const Node &b){
    return a.p > b.p;
  });
  int l = 0, r = n - 1;
  for (;;) {
    k[l + 1] += p[l] * k[l];
    
  }
}