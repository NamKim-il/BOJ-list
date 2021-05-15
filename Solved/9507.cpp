#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long a[70]={1,1,2,4},n,d;
    for(int i=4;i<70;i++)
        a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
    cin>>n;
    while(n-->0) {
        cin>>d;
        cout<<a[d]<<endl;
    }
}
