//by zykykyk
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<vector>
#include<map>
#define For(i,x,y) for (int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (int i=(x);i>=(y);i--)
#define cross(i,k) for (int i=first[k];i;i=last[i])
#define il inline
#define vd void
#define ll long long
#define N 50010
using namespace std;
il int read(){
    int x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
struct query{
    ll l,r,id;
}ask[N];
struct answer{
    ll x,y;
}ans[N],now;
int n,m,l,r,len,id[N],c[N];
ll cnt[N];
il bool cmp(query x,query y){
    if (id[x.l]==id[y.l]){
        if (id[x.l]&1==1) return x.r<y.r;
        else return x.r>y.r;	
    }
    else return id[x.l]<id[y.l];
}
il ll gcd(ll x,ll y){return !y?x:gcd(y,x%y);}
il vd Divgcd(ll x,ll y,int id){
    if (!x) x=0,y=1;
    else {
        ll Gcd=gcd(x,y);
        x/=Gcd,y/=Gcd;
    }
    ans[id].x=x,ans[id].y=y;
}
il vd add(int x){
    cnt[x]++;
    if (cnt[x]>1) now.x=now.x+cnt[x]*(cnt[x]-1)-(cnt[x]-1)*(cnt[x]-2);
}
il vd del(int x){
    cnt[x]--;
    if (cnt[x]>0) now.x=now.x+cnt[x]*(cnt[x]-1)-(cnt[x]+1)*cnt[x];
}
int main(){
  freopen("data.in", "r", stdin);
    n=read(),m=read();
    len=sqrt(n);
    For(i,1,n) c[i]=read(),id[i]=(i-1)/len+1;
    For(i,1,m){
        ask[i].l=read(),ask[i].r=read(),ask[i].id=i;
    } 
    sort(ask+1,ask+1+m,cmp);
    For(i,ask[1].l,ask[1].r) add(c[i]);
    now.y=(ask[1].r-ask[1].l+1)*(ask[1].r-ask[1].l);
    Divgcd(now.x,now.y,ask[1].id);
    l=ask[1].l,r=ask[1].r;
    For(i,2,m){
        while (l<ask[i].l) del(c[l++]);
        while (l>ask[i].l) add(c[--l]);
        while (r<ask[i].r) add(c[++r]);
        while (r>ask[i].r) del(c[r--]);
        now.y=(ask[i].r-ask[i].l+1)*(ask[i].r-ask[i].l);
        Divgcd(now.x,now.y,ask[i].id);
    }
    For(i,1,m) printf("%lld/%lld\n",ans[i].x,ans[i].y);
}