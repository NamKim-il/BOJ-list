#include<queue>
#include<iostream>
using namespace std;
int n, m;
int mp[2005][2005];//0~n-1
bool chk[2005][2005];
int par[100005];//1~m
int nx[4]={0,1,0,-1};
int ny[4]={1,0,-1,0};
queue<pair<pair<int,int>,int>> q;
int findp(int i)
{
    if(par[i]==i) return i;
    else return par[i]=findp(par[i]);
}
void bfs()
{
    int siz=q.size();
    for(int i=0;i<siz;i++)
    {
        int nowx=q.front().first.first, nowy=q.front().first.second;
        mp[nowx][nowy]=q.front().second;
        q.pop();
        for(int j=0;j<4;j++) {
            int newx=nowx+nx[j], newy=nowy+ny[j];
            if(newx<0||newx>=n||newy<0||newy>=n) continue;

            if(mp[newx][newy]) {
                
                int nowpar=findp(mp[nowx][nowy]);
                int newpar=findp(mp[newx][newy]);   
                if(nowpar!=newpar) {
                    par[min(nowpar,newpar)]=max(nowpar, newpar);
                    m--;
                }
            }
            else if(!chk[newx][newy]){
                chk[newx][newy]=1;
                // for(int k=0;k<4;k++) {
                //     int gox=newx+nx[k], goy=newy+ny[k];
                //     if(gox<0||gox>=n||goy<0||goy>=n) continue;
                //     if(mp[gox][goy]&&mp[gox][goy]!=mp[nowx][nowy]) {
                //         int nowpar=findp(mp[nowx][nowy]);
                //         int gopar   =findp(mp[gox][goy]);
                //         if(nowpar!=gopar) m--;
                //         par[min(nowpar, gopar)]=max(nowpar, gopar);
                //     }
                // }
                q.push({{newx, newy},mp[nowx][nowy]});
            }
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int ans=0;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
       int a, b;
       cin>>a>>b;
       mp[a-1][b-1]=i+1;
       par[i+1]=i+1;
       q.push({{a-1, b-1},i+1});
       chk[a-1][b-1]=1;
    }
    bfs();
    while(m>1) {
        bfs();
        //  for(int i=1;i<=n;i++) {
        //     for(int j=1;j<=n;j++) {
        //         cout<<mp[i-1][j-1]<<' ';
        //     }
        //     cout<<'\n';
        // }
        // cout<<'\n';
        ans++;
    }
    cout<<ans;

}   