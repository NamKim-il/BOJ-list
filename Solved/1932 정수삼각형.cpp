
#include<bits/stdc++.h>
using namespace std;
int a[600][600], b[600][600];
int mx(int a, int b)
{
    return a>b? a:b;
}
int main()
{
    int n,i,j,max=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            b[i][j]=mx(b[i+1][j+1],b[i+1][j])+a[i][j];
        }

    }
    cout<<b[0][0];

}
