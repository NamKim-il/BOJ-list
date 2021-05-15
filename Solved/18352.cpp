#include<bits/stdc++.h>
using namespace std;
int n, m, k, st;
vector<int> node[300005];
int chk[300005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k>>st;
    for(int i=0;i<m;i++) {
        int x, y;
        cin>>x>>y;
        node[x].push_back(y);
    }
    queue<int> q;
    q.push(st);
    chk[st]=1;
    while(!q.empty()) {
        int now=q.front();
        q.pop();
        for(auto i:node[now]) {
            if(!chk[i]) {
                chk[i]=chk[now]+1;
                q.push(i);
            }
        }
    }
    bool f=true;
    for(int i=1; i<=n;i++) {
        if(chk[i]==k+1) {
            f=false;
            cout<<i<<' ';
        }
    }
    if(f) cout<<-1;
}