#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[100001];
vector<pair<int,int>> v2[100001];
int deg[100001];
int tim[100001];
int chk[100001];
int ans;
queue<int> q;
void dfs(int now)
{
    ans++;
    chk[now]=1;
    for(auto i:v2[now])
    {
        if(tim[i.first]+i.second==tim[now])
        {
            if(!chk[i.first])
                dfs(i.first);
            else ans++;
        }
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    int stp, endp;
    for(int i=0;i<m;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v2[b].push_back({a,c});
        deg[b]++;
    }
    cin>>stp>>endp;
    q.push(stp);

    while(!q.empty())
    {
        int now=q.front(); q.pop();
        for(auto i:v[now])
        {
            deg[i.first]--;
            if(!deg[i.first]) q.push(i.first);
            tim[i.first]=max(tim[i.first],tim[now]+i.second);
        }
        endp=now;
    }
    dfs(endp);
    cout<<tim[endp]<<'\n'<<ans-1;

}
