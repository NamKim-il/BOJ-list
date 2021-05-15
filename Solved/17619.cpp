#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>,int>> v;
int ans[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, cnt=0, ed=-1;
    cin>>n>> m;
    for(int i=0;i<n;i++)
    {
        int b, c, d;
        cin>>b>>c>>d;
        v.push_back({{b,c},i+1});
    }
    sort(v.begin(), v.end());
    for(auto i:v)
    {
        if(ed<i.first.first) {
            cnt++;
        }
        ed=max(ed, i.first.second);
        ans[i.second]=cnt;
    }
    for(int i=0;i<m;i++)
    {
        int x, y;
        cin>>x>>y;
        cout<<(ans[x]==ans[y])<<'\n';
    }
}
