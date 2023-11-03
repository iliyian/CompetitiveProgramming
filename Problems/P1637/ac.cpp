#include<bits/stdc++.h>
#define MAXN 30001
#define ls root<<1,l,mid
#define rs root<<1|1,mid+1,r
#define int long long
#define in(x) x=read()

using namespace std;

inline int read()
{
    int X=0,w=1;char ch=getchar();
    while(ch>'9' || ch<'0'){if(ch=='-') w=-1;ch=getchar();}
    while(ch<='9' && ch>='0') X=(X<<3)+(X<<1)+ch-'0',ch=getchar();
    return X*w;
}

struct Data
{
    int num,pos;
}st[MAXN];
int n,cnt;
int sum[MAXN<<2],num[MAXN],bigger[MAXN],smaller[MAXN];
long long ans;

inline void push_up(int root)
{
    sum[root]=sum[root<<1]+sum[root<<1|1];
}

inline void update(int root,int l,int r,int pos)
{
    if(l==r && l==pos){sum[root]++;return;}
    int mid=(l+r)>>1;
    if(mid>=pos) update(ls,pos);
    if(mid<pos) update(rs,pos);
    push_up(root);
}

inline int query(int root,int l,int r,int L,int R)
{
    if(L<=l && r<=R) return sum[root];
    int mid=(l+r)>>1,total=0;
    if(mid>=L) total+=query(ls,L,R);
    if(mid<R) total+=query(rs,L,R);
    return total; 
}

inline bool mcomp(const Data &a,const Data &b)
{
    return a.num<b.num;
}

signed main()
{
  freopen("data.in", "r", stdin);
    in(n);
    for(int i=1;i<=n;i++) in(st[i].num),st[i].pos=i;
    sort(st+1,st+n+1,mcomp);
    for(int i=1;i<=n;i++) 
    {
        if(st[i].num>st[i-1].num) cnt++;
        num[st[i].pos]=cnt; 
    }
    //离散化,注意两个数相同的情况 
    for(int i=1;i<=n;i++)
    {
        if(num[i]>1) smaller[i]=query(1,1,n,1,num[i]-1);
        update(1,1,n,num[i]);
    }
    //查询一个数前比它小的数的个数
    memset(sum,0,sizeof(sum));
    //注意清空sum数组 
    for(int i=n;i>=1;i--)
    {
        if(num[i]<n) bigger[i]=query(1,1,n,num[i]+1,n);
        update(1,1,n,num[i]);
    }
    //查询一个数后比它大的数的个数 
    for(int i=1;i<=n;i++) ans+=(bigger[i]*smaller[i]);
    //乘法原理 & 加法原理 
    printf("%lld",ans);
    return 0;
}
//By windows250