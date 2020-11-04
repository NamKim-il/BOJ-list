#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[101];
int cnt[101];
int ans[101][101];
vector<int> base;
queue<int> q;
int main()
{
    int n ,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        v[b].push_back({a,c});
        cnt[a]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!cnt[i])
        {
            base.push_back(i);
            q.push(i);
            ans[i][i]=1;
        }
    }
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(auto p:v[now])
        {
            for(auto i:base)
            {
                ans[p.first][i]+=ans[now][i]*p.second;
            }
            cnt[p.first]--;
            if(!cnt[p.first]) q.push(p.first);
        }
    }
    for(auto i:base)
    {
        cout<<i<<' '<<ans[n][i]<<'\n';
    }
}
