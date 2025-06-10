#include <bits/stdc++.h>

typedef long long int64;

const int mod=1'000'000'007;

void work(){
  int n;
  std::cin>>n;
  n>>=1;
  std::cout<<1LL*n*(n+1)%mod<<'\n';
}

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int T=1;
  std::cin>>T;
  for (;T--;) work();
  return 0;
}