#include<bits/stdc++.h>
using namespace std;
pair<vector<int>,int> inter[500002];
pair<vector<int>,int> scc_node[500002];
stack<int> S;
vector<pair<vector<int>,int>> SCC;
bool visited[500002];
int dfsnum[500002],nodes[500002],maxi[500002],cnt,sccnum=1;
int dfs(int curr)
{
    dfsnum[curr]=cnt++;
    int result=dfsnum[curr];
    S.push(curr);
    auto i=inter[curr].first.begin();
    while(i<inter[curr].first.end())
    {
        if(dfsnum[*i]==0) result=min(result,dfs(*i));
        else if(!visited[*i]) result=min(result,dfsnum[*i]);
        i++;
    }
    if(result==dfsnum[curr]) {
        pair<vector<int>,int> currSCC;
        currSCC.second=0;
        while(1){
            int t=S.top();
		     S.pop();
            currSCC.first.push_back(t);
            currSCC.second+=inter[t].second;
            visited[t]=true;
            nodes[t]=sccnum;
            if(t==curr) break;
        }
        SCC.push_back(currSCC);
        sccnum++;
    }
    return result;
}
void calc(int start)
{
    maxi[start]=scc_node[start].second;
    queue<int> qu;
    qu.push(start);
    while(!qu.empty())
    {

        int top=qu.front();
        qu.pop();
        auto ite=scc_node[top].first.begin();
        while(ite<scc_node[top].first.end())
        {
            if(maxi[*ite]<maxi[top]+scc_node[*ite].second)
            {
                maxi[*ite]=maxi[top]+scc_node[*ite].second;
                qu.push(*ite);
            }
            ite++;

        }
	}
}
int main()
{
    //memset(nodes,-1,sizeof(nodes));
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m,i,l,k,start,ans=0;
    cin>>n>>m;
    int a[2][m];
    int outback[n]={0,};
    for(i=0;i<m;i++)
    {
        cin>>a[0][i]>>a[1][i];
        inter[a[0][i]].first.push_back(a[1][i]);
    }
    for(i=1;i<=n;i++)
        cin>>inter[i].second;
    cin>>start>>l;

    dfs(start);
    for(i=0;i<l;i++) {
        cin>>k;
        outback[i]=k;
    }

    for(i=0;i<m;i++)
    {
        if(nodes[a[0][i]]>=0&&nodes[a[1][i]]>=0)
            if(nodes[a[0][i]]!=nodes[a[1][i]]){
                scc_node[nodes[a[0][i]]].first.push_back(nodes[a[1][i]]);
            }
    }
    for(i=0;i<sccnum;i++)
    {
        int check[sccnum]={0,};
        if(scc_node[i].first.empty()) continue;
        auto iter=scc_node[i].first.begin();
        while(iter<scc_node[i].first.end())
        {
            if(check[*iter]==0) check[*iter]=1;
            else scc_node[i].first.erase(iter);
            iter++;
        }
    }
	/*연결 확인 코드
	for(i=0;i<sccnum;i++)
    {
        int check[sccnum]={0,};
        if(scc_node[i].first.empty()) continue;
        auto iter=scc_node[i].first.begin();
       cout<<i<<endl;
		while(iter<scc_node[i].first.end())
        {
            cout<<*iter<<endl;
			iter++;
        }
		cout<<endl;
    }
	*/
    for(i=1;i<sccnum;i++) scc_node[i].second=SCC[i-1].second;
    int st=nodes[start];
    calc(st);
	for(i=0;i<l;i++)
    {
        ans=max(ans,maxi[nodes[outback[i]]]);

    }
    cout<<ans;
}
