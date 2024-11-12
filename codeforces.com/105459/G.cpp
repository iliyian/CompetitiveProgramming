#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+10;
int father[maxn],rk[maxn];
void init(int n)
{
  for(int i=0;i<=n;i++)
  {
    father[i]=i;rk[i]=1;
  }
}
int find(int u)
{
  return u==father[u]?u:find(father[u]);
}
bool isSame(int u,int v)
{
  u=find(u);v=find(v);return u==v;
}
void join(int u,int v)
{
  u=find(u);v=find(v);
  if(rk[u]<=rk[v])
  {
    father[u]=v;
  }
  else father[v]=u;
  if((rk[u]==rk[v])&&(u!=v))rk[v]++;
}
int n,m,k;
bool mp[maxn];
vector<int>v[maxn];
void solve() 
{
  cin>>n>>m>>k;
  init(n);
  for(int i=1;i<=k;i++)
  {
    //cin>>a[i];
    int x;
    cin>>x;
    mp[x]=true;
  }
  for(int i=1;i<=m;i++)
  {
    int p,q;
    cin>>p>>q;
    join(p,q);
    v[p].push_back(q);
    v[q].push_back(p);
  }
  if(k==n)
  {
    cout<<"No"<<endl;
    return;
  }
  int qq=0;
  for(int i=1;i<=n;i++)
  {
    if(find(i)!=i)qq++;
  }
  if(qq!=n-1)
  {
    cout<<"No"<<endl;
    return;
  }
  init(n);
  int f=0;
  int t=0,sum=n;
  map<int,vector<int>>vi;
  for(int i=1;i<=n;i++)
  {
    int tmp=0;
    if(i==1){ ;}
    else if(!isSame(i,1)||mp[i]==true)continue;
    for(auto u:v[i])
    {
      if(!isSame(i,u))
      {
        join(i,u);
        tmp++;
        vi[i].push_back(u);
      }
    }
    if(tmp)t++;
    //cout<<tmp;
    // for(auto i:vi)
    // {
    //   cout<<i<<' ';
    // }
    sum-=tmp;
    if(sum==1)
    {
      f=1;
      break;
    }
  }
  if(f==0)
  {
    cout<<"No"<<endl;
    return;
  }
  cout<<"Yes"<<endl;
  cout<<t<<endl;
  for(auto &i:vi)
  { 
    cout<<i.first<<' ';
    cout<<i.second.size()<<' ';
    for(auto &u:i.second)
    {
      cout<<u<<' ';
    }
    cout<<endl;
  }
}
signed main() 
{
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t=1;
  //std::cin >> t;
  while (t--) 
  {
    solve();
  }
  return 0;
}