#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define maxn 100010
using namespace std;
int f[maxn];
int a,b,p,ans;
bool prime[maxn];
int vis[maxn];
int cnt;
int getf(int x)
{
    if(f[x]==x) return x;
    else
    {
        f[x]=getf(f[x]);
        return f[x];
    }
}
int merge(int x,int y)
{
    int t1=getf(x),t2=getf(y);
    if(t1!=t2)
    {
        f[t2]=t1;
        return 1;
    }
    return 0;
}
int make_prime()      //普通筛 
{
    memset(prime,1,sizeof(prime));
    int k=sqrt(b);
    prime[0]=prime[1]=0;
    for(int i=2;i<=k;i++)
        if(prime[i])
            for(int j=2*i;j<maxn;j+=i) prime[j]=0;
}
int main()
{
    cin>>a>>b>>p;
    for(int i=a;i<=b;i++) f[i]=i;
    make_prime();
    for(int i=p;i<=b;i++)      //找出p~b之间的素数 
        if(prime[i]) vis[++cnt]=i;  //记录 
    for(int i=1;i<=cnt;i++)     //找出a~b之间符合条件的数，合并 
    {
        int cc=0;
        while(cc*vis[i]<a) cc++;     //确保是a~b之间的，不要超范围，不然后面没法统计 
        while(vis[i]*(cc+1)<=b)
        {
            merge(vis[i]*cc,vis[i]*(cc+1));     //合并 
            cc++;
        }
    }
    for(int i=a;i<=b;i++)
        if(f[i]==i) ans++;     //统计个数 
    cout<<ans<<endl;
    return 0;
}