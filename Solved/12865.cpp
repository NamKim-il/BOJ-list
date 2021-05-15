#include<bits/stdc++.h>
using namespace std;
int arr[100][100001];
int main()
{
    int n, m, x, y;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>y>>x;
        if(i==0) arr[i][y]=x;
        else {
            for(int k=0;k<= m;k++) {
                if(k>=y)
                    arr[i][k]=max(arr[i-1][k-y]+x,arr[i-1][k]);
                else arr[i][k]=arr[i-1][k];
            }
        }
    }
    int _max=0;
    for(int i=0;i<=m;i++)
        _max=max(_max, arr[n-1][i]);
    cout<<_max;
}
