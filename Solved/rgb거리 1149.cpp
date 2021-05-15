#include<bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return a<b?a:b;
}
int main()
{
    int n;
    cin>>n;
    int a[3][n],b[3][n]={0,};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[j][i];
        }
    }
    for(int i=0;i<3;i++)
        b[i][0]=a[i][0];

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j==0)
                b[j][i]=max(b[1][i-1],b[2][i-1])+a[j][i];
            else if(j==1) b[j][i]=max(b[0][i-1],b[2][i-1])+a[j][i];
            else b[j][i]=max(b[0][i-1],b[1][i-1])+a[j][i];
        }
    }

    if(b[2][n-1]<=b[1][n-1]&&b[2][n-1]<=b[0][n-1])
       cout<<b[2][n-1];
    else if(b[1][n-1]<=b[0][n-1]&&b[1][n-1]<=b[2][n-1]) cout<<b[1][n-1];
    else cout<<b[0][n-1];
}
