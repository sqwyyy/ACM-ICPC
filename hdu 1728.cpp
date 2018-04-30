#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m,a,b,c,d,k,flag;
int vis[100+10][100+10];
char route[100+10][100+10];
int dir[100+10][100+10];
const int bx[]={1,-1,0,0};
const int by[]={0,0,1,-1};
int sum=1;
bool check(int x,int y)
{
    if(x<1||x>m||y<1||y>n||vis[x][y]||route[x][y]=='*') return false;
    return true;
}
void dfs(int x,int y,int dirt)
{
    if(!flag) return;
    if(dir[x][y]>k) return;
    if(dir[x][y]==k&&x!=c&&y!=d) return;
    if(x==c&&y==d&&dir[x][y]<=k)
    {
        flag=0;
        cout<<"yes"<<endl;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int fx=x+bx[i];
        int fy=y+by[i];
        if(!check(fx,fy)) continue;
        if(dir[x][y]>dir[fx][fy]) continue;
        if(i!=dirt && dir[fx][fy]<dir[x][y]+1) continue;
        if(i!=dirt)
            dir[fx][fy]=dir[x][y]+1;
        else
            dir[fx][fy]=dir[x][y];
        vis[fx][fy]=1;
        dfs(fx,fy,i);
        vis[fx][fy]=0;
    }
    vis[x][y]=0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        flag=1;
        memset(vis,0,sizeof(vis));
        memset(dir,0x7f,sizeof(dir));
        scanf("%d %d",&m,&n);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                cin>>route[i][j];
        scanf("%d %d %d %d %d",&k,&b,&a,&d,&c);
        vis[a][b]=1;
        dir[a][b]=0;
        for(int i=0;i<4;i++)
            dfs(a,b,i);
         if(flag) cout<<"no"<<endl;
    }
}
