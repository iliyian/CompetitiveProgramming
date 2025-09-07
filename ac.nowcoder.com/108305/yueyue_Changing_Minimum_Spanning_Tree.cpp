#include<bits/stdc++.h>
#define ll long long
#define N 400005
#define P 1000000007
using namespace std;
ll n=0,m=0,k,ans,fa[N],siz[N],s,block;
struct node{
    ll x,y,z;
}a[N];
vector<node> e;
ll ver[N],edge[N],Next[N],head[N],tot=0;
ll f[N][32],F[N][32],t=30,d[N];
void add(ll x,ll y,ll z)
{
    ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}
void dfs(int x)
{
    for (int i=head[x];i;i=Next[i])
    {
        ll y=ver[i],z=edge[i];
        if (d[y])continue;
        d[y]=d[x]+1;
        f[y][0]=x;
        F[y][0]=z;
        for (int j=1;j<=t;j++)f[y][j]=f[f[y][j-1]][j-1],F[y][j]=max(F[y][j-1],F[f[y][j-1]][j-1]);
        dfs(y);
    }
}
ll lca(ll x,ll y)
{
    if (d[x]<d[y])swap(x,y);
    for (int i=t;i>=0;i--)if(d[f[x][i]]>=d[y])x=f[x][i];
    if (x==y)return x;
    for (int i=t;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
ll query(ll x,ll y)
{
    ll val=0;
    if (x==y)return val;
    for (int i=t;i>=0;i--)
    if(d[f[x][i]]>d[y])
    {
        val=max(val,F[x][i]);
        x=f[x][i];
    }
    val=max(val,F[x][0]);
    return val;
}
ll query_max(ll x,ll y)
{
    ll LCA=lca(x,y);
    return max(query(x,LCA),query(y,LCA));
}
bool cmp(node x,node y)
{
    return x.z<y.z;
}
ll get(ll x)
{
    if (fa[x]==x)return x;
    return fa[x]=get(fa[x]);
}
void solve()
{
    e.clear();
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)fa[i]=i,siz[i]=1,head[i]=d[i]=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=t;j++)f[i][j]=F[i][j]=0;
    for (int i=1;i<=tot;i++)edge[i]=ver[i]=Next[i]=0;
    tot=0;
    for (int i=1;i<=m;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    block=n;
    ans=s=0;
    sort(a+1,a+m+1,cmp);
    for (int i=1;i<=m;i++)
    {
        int x=get(a[i].x),y=get(a[i].y);
        if (x==y)
        {
            e.push_back(a[i]);
            continue;
        }
        add(a[i].x,a[i].y,a[i].z);
        add(a[i].y,a[i].x,a[i].z);
        s=(s+a[i].z)%P;
        ans=(ans+siz[x]*siz[y]%P*a[i].z%P)%P;
        siz[x]+=siz[y];
        fa[y]=x;
        block--;
    }
    if (block>2)
    {
        cout<<0<<endl;
        return ;
    }
    if (block==2)
    {
        ll x=get(1),y=0;
        for (int i=2;i<=n;i++)
        {
            if (get(i)!=x)
            {
                y=get(i);
                break;
            }
        }
        cout<<siz[x]*siz[y]%P*k%P<<endl;
        return ;
    }
    ans=(ans-s+P)%P;
    dfs(1);
    for (auto [x,y,z]:e)
    {
//        cout<<'!'<<x<<' '<<y<<' '<<lca(x,y)<<' '<<query_max(x,y)<<endl;
        ans=(ans+P-query_max(x,y))%P;
    }
    ans=((ans+P-n*(n-1)/2%P)%P+m)%P;
    while(ans<0)ans+=P;
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}