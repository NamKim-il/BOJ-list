#include<bits/stdc++.h>
using namespace std;
long long a[1000005],n,m;
long long sum(long long height)
{
    long long su=0;
    for(long long i=0;i<n;i++)
        if(a[i]>height) su+=a[i]-height;
    return su;
}
long long eeebun(long long low,long long high)
{
    if(low==high)
        return low;
    if(low+1==high)
    {
        if(sum(high)>m) return high;
        else return low;

    }
    long long mid=(low+high)/2;
    long long su=sum(mid);
    if(su==m) return mid;
    else if(su>m) return eeebun(mid,high);
    else if(su<m) return eeebun(low,mid);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long ans=eeebun(0,1000000000);
    if(sum(ans)<m) cout<<ans-1;
    else cout<<ans;

}
