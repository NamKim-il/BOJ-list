#include<iostream>
using namespace std;
int a[45][2];
int main()
{
    int n, i,k;
    a[0][0]=1;
    a[1][1]=1;
    for(i=2;i<44;i++)
    {
        a[i][0]=a[i-1][0]+a[i-2][0];
        a[i][1]=a[i-1][1]+a[i-2][1];
    }
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        cout<<a[k][0]<<" "<<a[k][1];
        if(i<n-1) cout<<endl;
    }
}
