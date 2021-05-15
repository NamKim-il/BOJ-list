#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    long long a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        cin>>a;
        b=a;
        while(a/10>0) {
                cnt++;
                a=a/10;
        }
        a=1;
        for(int j=0;j<cnt;j++) a=a*10+1;
        int ans=cnt*9;
        for(int j=1;j<10;j++) if(j*a>b) break;
        cout<<ans+j-1<<'\n';

    }


}
