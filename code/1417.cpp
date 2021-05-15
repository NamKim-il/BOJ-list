#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[1000];
    int n, _max=0;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(i>0)
            _max=max(arr[i], _max);
    }
    for(int j=_max;j>=0;j--) {
        int sum=0;
        for(int i=1;i<n;i++) if(arr[i]>j) sum+=arr[i]-j;
        if(arr[0]+sum>j) {
            if(j==_max) cout<<0;
            else 
                cout<<min(arr[0]+sum,j+2)-arr[0];
            break;
        }
    }

}