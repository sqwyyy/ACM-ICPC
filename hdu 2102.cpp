#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#define MAXN 200+10
using namespace std;
struct node
{
    int fx;
    int fy;
    int step;
    int flag;
    friend bool operator<(const node &x,const node &y)
    {
        return x.step>y.step;
    }
};
/*几个坑点
传送到另外一层的时候也是个传送门就会无限循环则把另一层的传送门改为障碍
还有一种传送直接到终点的*/
priority_queue<node>q;
int n,m,ok,time;//flag为0的时候表示在第一层为1表示在第二层
char route[2][MAXN][MAXN];
int bx[]={-1,1,0,0};
int by[]={0,0,1,-1};
int vis[2][MAXN][MAXN];
bool check(int x,int y,int z)
{
    if(x<0||x>=n||y<0||y>=m) return false;
    else if(vis[z][x][y]||route[z][x][y]=='*') return false;
    return true;
}
void bfs(int x,int y,int step)
{
    q.push((node){x,y,step,0});
    while(!q.empty())
    {
        node ss=q.top();
        q.pop();
        if(ok) continue;
        if(route[ss.flag][ss.fx][ss.fy]=='P')
        {
            if(time>=ss.step)
            {
                cout<<"YES"<<endl;
                ok=1;
            }
        }
        for(int i=0;i<4;i++)
        {
            node nw=ss;
            nw.fx+=bx[i];
            nw.fy+=by[i];
            nw.step++;
            if(check(nw.fx,nw.fy,nw.flag)&&nw.flag==0&&route[nw.flag][nw.fx][nw.fy]=='#')//在第一个地图
            {
                nw.flag=1;
                if(route[nw.flag][nw.fx][nw.fy]=='#')
                {
                    route[nw.flag][nw.fx][nw.fy]='*';//传送门过去还是传送门则把这里标记为障碍
                    continue;
                }
                if(route[nw.flag][nw.fx][nw.fy]=='P')
                {
                    if(time>=nw.step)
                    {
                        cout<<"YES"<<endl;
                        ok=1;
                    }
                }
                if(check(nw.fx,nw.fy,nw.flag))
                    nw.flag=1;
            }
            else if(check(nw.fx,nw.fy,nw.flag)&&nw.flag==1&&route[nw.flag][nw.fx][nw.fy]=='#')//在第二个地图
            {
                nw.flag=0;
                if(route[nw.flag][nw.fx][nw.fy]=='#')
                {
                    route[nw.flag][nw.fx][nw.fy]='*';//传送门过去还是传送门则把这里标记为障碍
                    continue;
                }
                if(route[nw.flag][nw.fx][nw.fy]=='P')
                {
                    if(time>=nw.step)
                    {
                        cout<<"YES"<<endl;
                        ok=1;
                    }
                }
                if(check(nw.fx,nw.fy,nw.flag))
                    nw.flag=0;
            }
            if(check(nw.fx,nw.fy,nw.flag))
            {
                //cout<<nw.flag<<" "<<nw.fx<<" "<<nw.fy<<" "<<nw.step<<endl;
                vis[nw.flag][nw.fx][nw.fy]=1;
                q.push(nw);
            }
        }
    }
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       ok=0;
       memset(vis,0,sizeof(vis));
        cin>>n>>m>>time;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>route[0][i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>route[1][i][j];
        vis[0][0][0]=1;
        bfs(0,0,0);
        if(!ok) cout<<"NO"<<endl;
        /*for(int i=0;i<n;i++)
        {
             for(int j=0;j<m;j++)
                 cout<<vis[0][i][j]<<" ";
            cout<<endl;
        }
         for(int i=0;i<n;i++)
        {
             for(int j=0;j<m;j++)
                 cout<<vis[1][i][j]<<" ";
            cout<<endl;
        }
   */}
   return 0;
}
