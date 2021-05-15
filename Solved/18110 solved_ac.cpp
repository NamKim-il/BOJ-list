#include<bits/stdc++.h>
using namespace std;
int rnd(double a)
{
    if(a-(int)a<0.5)
    {
        return (int)a;
    }
    return  (int)a+1;
}
int main()
{
    int n;
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
    }
    int a[n];
    int i,sum=0;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int k=rnd((double)n*0.15);
    for(i=k;i<n-k;i++)
        sum+=a[i];
    cout<<rnd((double)sum/(n-2*k));
}
