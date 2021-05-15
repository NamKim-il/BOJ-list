#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int i,j,k,n,m;
    char a[60][60]={0,};
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>a[i];
    int min=n>m?m:n;
    for(i=min-1;i>=0;i--)
    {
        for(j=0;j<n-i;j++)
        {
            for(k=0;k<m-i;k++)
            {
                if(a[j][k]==a[j][k+i])
                    if(a[j][k]==a[j+i][k])
                        if(a[j][k]==a[j+i][k+i])
                           {
                               cout<<(i+1)*(i+1);
                               return 0;
                           }
            }
        }

    }
}
