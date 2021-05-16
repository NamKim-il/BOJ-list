#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue < int > q;
    int n, k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        q.push(i);
    }
    int ans=0, tmp, x;
    while(k--) {
        x=0;
        cin>>tmp;
        for(int i=0;i<n;i++) {
            if(q.front()==tmp) {
                q.pop();
                break;
            }
            q.push(q.front());
            q.pop();
            x++;
        }
        ans+=min(x, n-x);
        n--;
    }
    cout<<ans;

}