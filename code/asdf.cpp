#include<bits/stdc++.h>
using namespace std;



int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    int k,l,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {


        cin>>k>>l>>a>>b;
        vector<vector<int>> node(200005);
        int x,y;
        for(int j=0;j<l;j++)
        {
            cin>>x>>y;
            node[x].push_back(y);
            node[y].push_back(x);
        }
        int check1[k+1]={0,},check2[k+1]={0,};
        queue<int> q;
        q.push(a);
        while(!q.empty())
        {
            int tmp=q.front();
            q.pop();
            for(int xx:node[tmp])
            {
                if(check1[xx]==0) q.push(xx);
            }
            check1[tmp]=1;
        }
        q.push(b);
        while(!q.empty())
        {
            int tmp=q.front();
            q.pop();
            for(int xx:node[tmp])
            {
                if(check2[xx]==0) q.push(xx);
            }
            check2[tmp]=-1;
            check1[tmp]-=1;
        }
        int ax=0,ay=0;
        for(int aa=1;aa<=k;aa++)
        {
            if(check1[a]==1) ax++;
            if(check1[a]==-1) ay++;
        }
        cout<<ax*ay<<'\n';

    }


}
