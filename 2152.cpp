#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<vector<int>> vrev;
vector<vector<int>> scc;
vector<vector<int>> vcc;
vector<int> nowscc;
stack<int> st;
int chk[10001];
int node[10001];
int cnt[10001], ans[10001];
int n ,m, stt, ed, scnt;
void dfs(int x)
{
    chk[x]=1;
    for(auto i:v[x])
    {
        if(!chk[i]) dfs(i);
    }
    st.push(x);
}
void revdfs(int x)
{
    chk[x]=1;
    nowscc.push_back(x);
    node[x]=scnt;
    for(auto i:vrev[x])
    {
        if(!chk[i]) revdfs(i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>stt>>ed;
    v.resize(n+1);
    vrev.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        vrev[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(!chk[i]) dfs(i);

    memset(chk, 0, sizeof(chk));
    while(!st.empty())
    {
        int tp=st.top(); st.pop();
        if(!chk[tp])
        {
            revdfs(tp);
            scc.push_back(nowscc);
            nowscc.clear();
            scnt++;
        }
    }
    vrev.clear();
    vcc.resize(scnt);
    for(int i=0;i<scnt;i++)
    {
        memset(chk, 0, (scnt+2)*4);
        for(auto j:scc[i])
        {
            for(auto k:v[j])
            {
                if(node[j]!=node[k] && !chk[node[k]])
                {
                    vcc[i].push_back(node[k]);
                    chk[node[k]]++;
                    cnt[node[k]]++;
                }
            }
        }
    }
    memset(chk, 0, sizeof(chk));
    stt=node[stt]; ed=node[ed];
    queue<int> q;

    for(int i=0;i<scnt;i++)
        if(!cnt[i]) q.push(i);

    while(stt!=q.front())
    {
        int now=q.front(); q.pop();
        for(auto i:vcc[now])
        {
            cnt[i]--;
            if(!cnt[i]) q.push(i);
        }
    }

    while(!q.empty()){
        int now=q.front(); q.pop();
        if(now==stt) continue;
        for(auto i:vcc[now]){
            cnt[i]--;
        }
    }
    q.push(stt);
    ans[stt]=scc[stt].size();
    while(!q.empty())
    {
        int now=q.front();q.pop();
        if(now==ed) break;
        for(auto i:vcc[now])
        {
            cnt[i]--;
            ans[i]=max(ans[i], ans[now]+(int)scc[i].size());
            if(!cnt[i])
            {
                q.push(i);
            }
        }
    }
    cout<<ans[ed];
}
