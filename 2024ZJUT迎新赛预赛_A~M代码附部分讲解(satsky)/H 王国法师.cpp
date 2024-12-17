#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
int chu[N];
/*
(先忽略特殊规则)
对于双方知道所有信息且必分胜负的博弈,可以:
称一个轮到谁谁就有必胜策略的局面为必胜态,反之为必败态(对手总有必胜策略)
必胜态即可转移到至少一个必败态,必败态即无法转移到任何必败态

在本题中,设初始局面为A,A移去点1的局面为B,B可一步转移到的所有局面的集合为S
若B为必败态则A为必胜态;若B为必胜态则集合S中至少有一个必败态,而A显然也可以转移到集合S中的所有局面,为必胜态
因此忽略特殊规则Alice必胜

判断特殊规则"只走一步"即判断这棵树是否为一条链/是否只有一个出度(作为u的次数)为0的点
*/
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        chu[u]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)if(chu[i]==0)cnt++;
    if(cnt<=1)
    {
        cout<<"Bob";
    }
    else
    {
        cout<<"Alice";
    }
    return 0;
}