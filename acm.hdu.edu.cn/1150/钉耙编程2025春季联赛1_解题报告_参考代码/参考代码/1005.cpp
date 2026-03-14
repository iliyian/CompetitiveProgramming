#include <bits/stdc++.h>

typedef long long int64;

const int N=100000;
const int64 INF=(1LL<<60)-1;
const int dx[4]={0,-1,0,1};
const int dy[4]={1,0,-1,0};

int n,m,t[N+9],d[N+9];

int Encode(int x,int y){return (x-1)*m+y;}
std::pair<int,int> Decode(int id){return std::make_pair((id-1)/m+1,(id-1)%m+1);}

void Read(){
  std::cin>>n>>m;
  for (int i=1;i<=n;++i)
    for (int j=1;j<=m;++j)
      std::cin>>t[Encode(i,j)];
  for (int i=1;i<=n;++i)
    for (int j=1;j<=m;++j)
      std::cin>>d[Encode(i,j)];
}

int64 dis[N+9][4];
bool vis[N+9][4];

void Dijkstra(){
  int st=Encode(1,1);
  int td=Encode(n,m);
  for (int i=1;i<=n*m;++i)
    for (int j=0;j<4;++j){
      dis[i][j]=INF;
      vis[i][j]=0;
    }
  std::priority_queue<
    std::tuple<int64,int,int>,
    std::vector<std::tuple<int64,int,int>>,
    std::greater<std::tuple<int64,int,int>>> pq;
  dis[st][0]=t[st];pq.emplace(0,st,0);
  for (;!pq.empty();){
    auto [val,p,u]=pq.top();pq.pop();
    if (vis[p][u]) continue;
    vis[p][u]=1;
    for (int v=0;v<4;++v){
      if (dis[p][u]+d[p]>=dis[p][v]) continue;
      dis[p][v]=dis[p][u]+d[p];
      pq.emplace(dis[p][v],p,v);
    }
    auto [x,y]=Decode(p);
    x+=dx[u];y+=dy[u];
    int q=Encode(x,y);
    auto OutMap=[&](int x,int y){
      return x<1||x>n||y<1||y>m;
    };
    if (!OutMap(x,y)&&dis[p][u]+t[q]<dis[q][u]){
      dis[q][u]=dis[p][u]+t[q];
      pq.emplace(dis[q][u],q,u);
    }
  }
  std::cout<<dis[td][3]<<'\n';
}

void work(){
  Read();
  Dijkstra();
}

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int T=1;
  std::cin>>T;
  for (;T--;) work();
  return 0;
}