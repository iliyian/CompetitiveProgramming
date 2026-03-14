#include <bits/stdc++.h>

typedef long long int64;

const int N=100000,C=19,INF=(1<<30)-1;

int n,cq,a[N+9],ql[N+9],qr[N+9];

void Read(){
  std::cin>>n>>cq;
  for (int i=1;i<=n;++i)
    std::cin>>a[i];
  for (int i=1;i<=cq;++i)
    std::cin>>ql[i]>>qr[i];
}

void Reverse(){
  for (int i=1;i<=n;++i) a[i]=-a[i];
}

int ans[N+9];

void Out(){
  int R=0;
  for (int i=1;i<=cq;++i){
    R=(R+1LL*i*ans[i])%1'000'000'007;
    // std::cout<<ans[i]<<'\n';
  }
  std::cout<<R<<'\n';
  for (int i=1;i<=cq;++i) ans[i]=0;
}

int lg[N+9],max[C][N+9],min[C][N+9];

void InitST(){
  for (int i=2;i<=n;++i) lg[i]=lg[i>>1]+1;
  for (int i=1;i<=n;++i){
    max[0][i]=i&1?-INF:a[i];
    min[0][i]=i&1?a[i]:INF;
  }
  for (int i=1;i<C;++i)
    for (int j=1;j+(1<<i)-1<=n;++j){
      max[i][j]=std::max(max[i-1][j],max[i-1][j+(1<<(i-1))]);
      min[i][j]=std::min(min[i-1][j],min[i-1][j+(1<<(i-1))]);
    }
}

bool Query(int l,int r){
  int t=lg[r-l+1];
  int u=std::min(min[t][l],min[t][r-(1<<t)+1]);
  int d=std::max(max[t][l],max[t][r-(1<<t)+1]);
  return u>d;
}

int pos[N+9],len[C][N+9];

void InitLen(){
  for (int i=1;i<C;++i)
    for (int j=1;j+(1<<i)-1<=n;++j)
      len[i][j]=std::max(len[i-1][j],len[i-1][j+(1<<(i-1))]);
}

int QueryLen(int l,int r){
  int t=lg[r-l+1];
  return std::max(len[t][l],len[t][r-(1<<t)+1]);
}

void Solve(){
  InitST();
  for (int i=1,j=1;i<=n;++i){
    for (;j<=i&&!Query(j,i);++j);
    pos[i]=j;
    len[0][i]=i-j+1;
  }
  InitLen();
  for (int i=1;i<=cq;++i){
    int l=ql[i],r=qr[i];
    int x=std::lower_bound(pos+l,pos+r+1,l)-pos;
    ans[i]=std::max(ans[i],x-l);
    if (x<=r)
      ans[i]=std::max(ans[i],QueryLen(x,r));
  }
}

void work(){
  Read();
  Solve();
  Reverse();
  Solve();
  Out();
}

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int T=1;
  std::cin>>T;
  for (;T--;) work();
  return 0;
}