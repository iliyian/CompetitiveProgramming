#include<bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;
int n,m,k,flag,maxn;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
bool check(int x,int y)
{
    if (x>=1&&y>=1&&x<=n&&y<=m)return 1;
    return 0;
}
void work(int x,int y,vector<vector<int> > &vis)
{
//    cout<<x<<' '<<y<<endl;
    vis[x][y]=1;
    for (int i=0;i<4;i++)
    {
        if (i==2)continue;
        int X=x+dx[i],Y=y+dy[i];
        if (check(X,Y)&&vis[X][Y]==0)work(X,Y,vis);
    }
}
void dfs(int x,int y,vector<vector<int> > &vis,vector<vector<int> > &b)
{
//    cout<<x<<' '<<y<<endl;
    maxn=max(maxn,b[x][y]);
    if (b[x][y]!=0)return ;
    b[x][y]=-1;
    for (int i=0;i<=3;i++)
    {
        int X=x+dx[i],Y=y+dy[i];
        if (check(X,Y)&&vis[X][Y]==0)dfs(X,Y,vis,b);
    }
}
void dfs1(int x,int y,vector<vector<int> > &vis,vector<vector<int> > &b)
{
    if (b[x][y]!=0&&b[x][y]!=-1)return ;
    b[x][y]=maxn;
    for (int i=0;i<=3;i++)
    {
        int X=x+dx[i],Y=y+dy[i];
        if (check(X,Y)&&vis[X][Y]==0)dfs1(X,Y,vis,b);
    }
}
void bfs(int x,int y,vector<vector<int> > &vis,vector<vector<int> > &b,vector<vector<int> > &v)
{
    if (flag==0)return ;
    v[x][y]=1;
//    cout<<x<<' '<<y<<endl;
    for (int i=0;i<3;i++)
    {
        int X=x+dx[i],Y=y+dy[i];
        if (!check(X,Y))continue;
        if (v[X][Y])continue;
        if (vis[X][Y])bfs(X,Y,vis,b,v);
        else {
            if (b[X][Y]-y>=k)
            {
                flag=0;
                return ;
            }
        }
    }
}
void solve()
{
    cin>>n>>m>>k;
    vector<vector<int> > vis(n+1,vector<int>(m+1)),v(n+1,vector<int>(m+1)),b(n+1,vector<int>(m+2));
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            char ch;
            cin>>ch;
            if (ch=='1')vis[i][j]=v[i][j]=1;
        }
    }
    work(1,m,vis);
//    cout<<"!"<<endl;
    for (int i=1;i<=n;i++)
        for (int j=m;j>0;j--)
        {
            if (vis[i][j]==0&&b[i][j]==0)
            {
                maxn=j;
                dfs(i,j,vis,b);
                dfs1(i,j,vis,b);
            }
            
        }
//    for (int i=1;i<=n;i++)
//    {
//        for (int j=1;j<=m;j++)
//        {
//            cout<<b[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    flag=1;
//    cout<<"!!"<<endl;
    bfs(1,1,vis,b,v);
//    cout<<flag<<endl;
    if (flag)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}