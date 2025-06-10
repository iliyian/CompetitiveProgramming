#include <bits/stdc++.h>

typedef long long int64;

const int mod=998244353,inv2=(mod+1)/2;

int Power(int a,int k){
  int res=1;
  for (;k;k>>=1,a=1LL*a*a%mod)
    if (k&1) res=1LL*res*a%mod;
  return res;
}

int Inv(int a){return Power(a,mod-2);}

void work(){
  int n,k,win;
  std::cin>>n>>k>>win;
  --win;
  std::vector<int> p(k),f(k,1);
  for (int &x:p){
    std::cin>>x;
    --x;
  }
  std::sort(p.begin(),p.end());
  int ans=1;
  for (;!p.empty();){
    std::vector<int> q,g;
    win>>=1;
    for (int i=0;i<(int)p.size();)
      if (win==(p[i]>>1)){
        ans=1LL*ans*(mod+1-f[i])%mod;
        i+=1;
      }else{
        q.push_back(p[i]>>1);
        if (i+1<(int)p.size()&&(p[i]>>1)==(p[i+1]>>1)){
          g.push_back(1LL*inv2*(f[i]+f[i+1])%mod);
          i+=2;
        }else if ((p[i]^1)<n){
          g.push_back(1LL*f[i]*inv2%mod);
          i+=1;
        }else{
          g.push_back(f[i]);
          i+=1;
        }
      }
    p=q;
    f=g;
    n=(n+1)>>1;
    // std::cerr<<"  \n";
    // for (int i=0;i<(int)p.size();++i)
    //   std::cerr<<p[i]<<" : "<<f[i]<<'\n';
  }
  std::cout<<ans<<'\n';
  // std::cerr<<1LL*inv2*inv2%mod<<'\n';
  // std::cerr<<3LL*inv2%mod*(1LL*inv2*inv2%mod)%mod<<'\n';
}

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  // std::cerr<<" 3/8 = "<<3LL*Inv(8)%mod<<'\n';
  int T=1;
  std::cin>>T;
  for (;T--;) work();
  return 0;
}