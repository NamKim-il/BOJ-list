#include<bits/stdc++.h>
using namespace std;
int ret[200000];
int main()
{
    int n, x, y;
    cin>>n;
    vector<int> color(n+1);
    vector<pair<int,pair<int,int>>> b(n);
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        b[i]={y,{x,i}};
    }
    sort(b.begin(), b.end());

    x=0;
    int sum=0, i=0;
    while(i<n) {
        int j=i;
        do {
           ret[b[j].second.second]=sum-color[b[j].second.first];
        } while(++j<n&&b[j].first==b[j-1].first);
        for(int k=i;k<j;k++)
        {
            sum+=b[k].first;
            color[b[k].second.first]+=b[k].first;
        }
        i=j;
    }

    for(int i=0;i<n;i++)
        cout<<ret[i]<<'\n';



}
