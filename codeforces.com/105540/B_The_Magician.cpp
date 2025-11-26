#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ch[300];
int n,a[6],t[7],b[6];
void copy(int *x,int *y)
{
    for (int i=1;i<=5;i++)x[i]=y[i];
}
int dfs(int dep,int c[6])
{
//        for (int i=1;i<=dep;i++)cout<<" ";
//        for (int i=1;i<=5;i++)cout<<c[i]<<' ';
//        cout<<endl;
    if (dep>4)
    {
        int tot=0;
        if (c[5])
        {
            for (int i=1;i<=4;i++)if (c[i]==4&&c[5])c[5]--,tot++;
            if (c[5]==2)
            {
                for (int i=1;i<=4;i++)if (c[i]==3&&c[5])c[5]-=2,tot++;
            }
        }
        return tot;
    }
    int d[6];
    copy(d,c);
    int tot=dfs(dep+1,d);
    if (t[dep])
    {
        //1
        
        for (int i=1;i<=4;i++)
        {
            if (i==dep||c[i]<1)continue;
            copy(d,c);
            d[dep]++,d[i]--;
            if (d[dep]>=5)d[dep]-=5,tot=max(tot,1+dfs(dep+1,d));
            else tot=max(tot,dfs(dep+1,d));
        }
        //2 1
        for (int i=1;i<=4;i++)
        {
            if (i==dep||c[i]<=1)continue;
            copy(d,c);
            d[dep]+=2,d[i]-=2;
            if (d[dep]>=5)d[dep]-=5,tot=max(tot,1+dfs(dep+1,d));
            else tot=max(tot,dfs(dep+1,d));
        }
        //3 1
        for (int i=1;i<=4;i++)
        {
            if (i==dep||c[i]<=2)continue;
            copy(d,c);
            d[dep]+=3,d[i]-=3;
            if (d[dep]>=5)d[dep]-=5,tot=max(tot,1+dfs(dep+1,d));
            else tot=max(tot,dfs(dep+1,d));
        }
        //2 2
        for (int i=1;i<=4;i++)
        {
            if (i==dep||c[i]==0)continue;
            for (int j=i+1;j<=4;j++)
            {
                if (j==dep||i==j||c[j]==0)continue;
                copy(d,c);
                d[dep]+=2,d[i]-=1,d[j]-=1;
                if (d[dep]>=5)d[dep]-=5,tot=max(tot,1+dfs(dep+1,d));
                else tot=max(tot,dfs(dep+1,d));
            }
        }
        //3 2
        for (int i=1;i<=4;i++)
        {
            if (i==dep||c[i]==0)continue;
            for (int j=1;j<=4;j++)
            {
                if (j==dep||i==j||c[j]<=1)continue;
                copy(d,c);
                d[dep]+=3,d[i]-=1,d[j]-=2;
                if (d[dep]>=5)d[dep]-=5,tot=max(tot,1+dfs(dep+1,d));
                else tot=max(tot,dfs(dep+1,d));
            }
        }
        //3 3
        bool flag=1;
        for (int i=1;i<=4;i++)
        {
            if (i==dep)continue;
            if (c[i]==0)flag=0;
        }
        if (flag)
        {
            copy(d,c);
            d[1]--,d[2]--,d[3]--,d[4]--;
            d[dep]+=4;
            if (d[dep]>=5)d[dep]-=5,tot=max(tot,1+dfs(dep+1,d));
            else tot=max(tot,dfs(dep+1,d));
        }
    }
    return tot;
}
void solve()
{
    int ans1=0,ans2=0;
    memset(a,0,sizeof(a));
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        a[ch[st[1]]]++;
    }
//    for (int i=1;i<=4;i++)cout<<a[i]<<endl;
    for (int i=1;i<=6;i++)cin>>t[i];
    for (int i=1;i<=4;i++)ans1+=a[i]/5,a[i]%=5;
    ans2=max(ans2,dfs(1,a));
    if (t[5])
    {
        if (t[6])
        {
            for (int i=1;i<=4;i++)
            {
                for (int j=1;j<=4;j++)
                {
                    copy(b,a);
                    b[i]--,b[j]--,b[5]+=2;
                    if (b[i]>=0&&b[j]>=0)ans2=max(ans2,dfs(1,b));
                }
            }
        }
        for (int i=1;i<=4;i++)
        {
            if (a[i]==0)continue;
            copy(b,a);
            b[i]--,b[5]++;
            ans2=max(ans2,dfs(1,b));
        }

    }
    else if (t[6])
    {
        for (int i=1;i<=4;i++)
        {
            for (int j=1;j<=4;j++)
            {
                if (a[j]==0||i==j)continue;
                copy(b,a);
                b[j]--,b[i]++;
                if (b[i]>=5)b[i]-=5,ans2=max(ans2,1+dfs(1,b));
                else ans2=max(ans2,dfs(1,b));
            }
        }
    }
    cout<<ans1+ans2<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    ch['D']=1,ch['C']=2,ch['H']=3,ch['S']=4;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}