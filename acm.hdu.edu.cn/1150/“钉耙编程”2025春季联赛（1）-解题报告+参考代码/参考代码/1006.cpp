#include <bits/stdc++.h>

typedef long long int64;

std::set<int> Solve(const std::vector<std::tuple<int,int,int>> &a){
  auto [x,y,z]=a[0];
  std::set<int> res;
  auto Try=[&](int x){
    if (x<0) return;
    for (auto [u,v,w]:a){
      if (1LL*u*x+v==w) continue;
      if (1LL*u*x+w==v) continue;
      if (1LL*v*x+u==w) continue;
      if (1LL*v*x+w==u) continue;
      if (1LL*w*x+u==v) continue;
      if (1LL*w*x+v==u) continue;
      return;
    }
    res.insert(x);
    // std::cerr<<x<<'\n';
  };
  Try((x-y)/z);
  Try((x-z)/y);
  Try((y-x)/z);
  Try((y-z)/x);
  Try((z-x)/y);
  Try((z-y)/x);
  return res;
}

void work(){
  int n;
  std::cin>>n;
  std::vector<std::tuple<int,int,int>> a(n);
  for (auto &[x,y,z]:a)
    std::cin>>x>>y>>z;
  auto t=Solve(a);
  assert(t.size()==1U);
  std::cout<<*t.begin()<<'\n';
}

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int T=1;
  std::cin>>T;
  for (;T--;) work();
  return 0;
}