#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, n;
    cin>>tc;
    while(tc--) {
        priority_queue<int> little;
        priority_queue<int, vector<int>, greater<int>> big;
        cin>>n;
        cout<<n/2+1<<'\n';
        for(int i=0;i<n;i++) 
        {
            int x;
            cin>>x;
            if(i==0 || x>big.top())
                big.push(x);
            else little.push(x);
            if(little.size()>big.size()) {
                big.push(little.top());
                little.pop();
            }
            if(little.size()+1<big.size()) {
                little.push(big.top());
                big.pop();
            }
            if(i%2==0) cout<<big.top()<<' ';
        }
        cout<<'\n';
    }
}