#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    int c[50], box[10000];
    cin>>n;
    for(int i=0;i<n;i++) cin>>c[i];
    sort(c, c+n);
    cin>>m;
    for(int i=0;i<m;i++) cin>>box[i];
    sort(box, box+m);
    if(box[m-1]>c[n-1]) {
        cout<<-1;
        return 0;
    }
    int ans=max((int)(box+m-upper_bound(box, box+m, c[n-2])), (m+n-1)/n);
    for(int i=n-2;i>=1;i--) {
        ans=max(ans, (int)(box+m-upper_bound(box, box+m, c[i-1])+n-i-1)/(n-i));
    }
    
    cout<<ans;
}