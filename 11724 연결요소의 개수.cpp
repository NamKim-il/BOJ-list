#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],b[1005];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int m,n,x,y,count=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==0){
            count++;
            q.push(i);
            b[i]=1;
            while(!q.empty()){
                y=q.front();
                q.pop();
                for(x=1;x<=n;x++){
                    if(a[y][x]==1&&b[x]==0){
                        q.push(x);
                        b[x]=1;
                    }

                }
            }
        }

    }
    cout<<count;
}
