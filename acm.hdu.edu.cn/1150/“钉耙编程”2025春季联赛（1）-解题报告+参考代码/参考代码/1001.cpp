#include <bits/stdc++.h>

typedef long long int64;

void work(){
  int n;
  std::string t;
  std::cin>>n>>t;
  int ans=-1;
  for (int i=1;i<=n;++i){
    std::string s;
    std::cin>>s;
    if (s==t){
      if (ans!=-1) assert(0);
      ans=i;
    }
  }
  std::cout<<ans<<'\n';
}

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int T=1;
  std::cin>>T;
  for (;T--;) work();
  return 0;
}