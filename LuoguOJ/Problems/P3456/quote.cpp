#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x,y;
    Node(int i=0,int j=0){
        x=i;y=j;    
}
};
queue <Node> q;
int dx[10]={0,0,1,1,1,-1,-1,-1},dy[10]={1,-1,0,-1,1,0,-1,1},sf,sg,p,n;
int a[1007][1007],ans;
bool v[1007][1007],flag;
void bfs(int sx,int sy){
    int col=a[sx][sy];//记录一下板块的颜色
    q.push(Node(sx,sy));
    for(int j=0;j<8;j++){//起点也要判定
        int xx=sx+dx[j];//判定周围八个点，这主要是来判断既不是山峰也不是山谷的情况
        int yy=sy+dy[j];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&a[xx][yy]!=col){//如果颜色不同，那么这就是这个板块“周围的点”
                if(p==-1) p=a[xx][yy];//如果还没有找到一个这样的点的话（-1是初始化），那么直接赋值
                else if((p-col>0&&a[xx][yy]-col<0)||(p-col<0&&a[xx][yy]-col>0)) {//如果这个板块周围出现既有比它大，又有比它小的情况，那么它就不是山峰或山谷，直接赋true
                flag=true;
                break;
            }
    }
}
    while(!q.empty()){
        Node cur=q.front();
        for(int i=0;i<8;i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&!v[nx][ny]&&a[nx][ny]==col){
                v[nx][ny]=true;
                q.push(Node(nx,ny));
                if(!flag)//如果我们已经发现它既不是山峰又不是山谷的话，那么直接淘汰，一心灌水就行了，不要傻乎乎地继续判定了
                    for(int j=0;j<8;j++){//判定和上面相同
                        int xx=nx+dx[j];
                        int yy=ny+dy[j];
                        if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&a[xx][yy]!=col){
                            if(p==-1) p=a[xx][yy];
                            else if((p-col>0&&a[xx][yy]-col<0)||(p-col<0&&a[xx][yy]-col>0)) {
                                flag=true;
                                break;
                            }
                        }
                    }
            }           
        }
        q.pop();    
    }
    if(flag) return;//不是山峰也不是山谷的情况
    if(p<col) sf++;//如果周边的点比它小，山峰，反之，山谷
    else sg++;
}
int main(){
    freopen("data.in", "r", stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!v[i][j]){
                v[i][j]=true;
                p=-1;flag=false;//初始p为-1，代表还没找到一个周围的点，p就是记录周围的点的，只要去记录第一个点，就能确定它是山峰还是山谷，或者啥也不是
                bfs(i,j);
                ans++;
            }   
    if(ans==1) printf("1 1");//注意特判，题目有说
    else printf("%d %d",sf,sg);
    return 0; 
}
