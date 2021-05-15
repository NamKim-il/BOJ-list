#include<bits/stdc++.h>
using namespace std;
typedef struct nod{
    int parent;
    int height;
}node;
bool check[200005];
vector< pair<vector<int>,node>> n(200005);
int bfs()
{
    queue<int> qu;
    int ind;
    qu.push(1);
    check[1]=true;
    while(!qu.empty())
    {
        ind=qu.front();
        qu.pop();
        auto iter=n[ind].first.begin();
        while(iter<n[ind].first.end()) {
            if(!check[*iter]){
                qu.push(*iter);
                n[*iter].second.parent=ind;
                n[*iter].second.height=n[ind].second.height+1;
                check[*iter]=true;
            }
            iter++;
        }
    }
}
int ans(int a,int b)
{
    while(n[a].second.height>n[b].second.height) a=n[a].second.parent;
    while(n[a].second.height<n[b].second.height) b=n[b].second.parent;
    while(a!=b)
    {
        if(a>1) a=n[a].second.parent;
        if(b>1) b=n[b].second.parent;
    }
    return a;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N,M,i,a,b;
    cin>>N;
    n[1].second.parent=1;
    n[1].second.height=1;
    for(i=0;i<N-1;i++)
    {
        cin>>a>>b;
        n[a].first.push_back(b);
        n[b].first.push_back(a);
    }
    bfs();
    cin>>M;
    for(i=0;i<M;i++)
    {
        cin>>a>>b;
        cout<<ans(a,b)<<"\n";
    }
}
