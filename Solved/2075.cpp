#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin>>n;
    for(int i=0;i<n*n;i++) {
        int x;
        cin>>x;
        if(pq.size()<n || pq.top()<x) pq.push(x);
        if(pq.size()>n)pq.pop(); 
    }
    cout<<pq.top();
}