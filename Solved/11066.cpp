#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;
vector<long long> x;
long long ans;
void cal(int n)
{
    if(n==0) return;
    auto it=x.begin();
    auto ittemp=it;
    long long min=MAX;
    for(;it<x.end()-1;it++)
    {
        if(*it+*(it+1)<min)
            {
                ittemp=it;
                min=*it+*(it+1);
            }
    }
    ans+=min;
    x.erase(ittemp,ittemp+2);
    x.insert(ittemp,min);
    cout<<min;
    cal(n-1);
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long i,n,a,b;
    cin>>n;
    while(n--)
    {
        ans=0;
        cin>>a;
        b=a;
        while(a--)
        {
            cin>>i;
            x.push_back(i);
        }
        cal(b-1);

        cout<<ans<<"\n";
    }
}
