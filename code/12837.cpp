#include<bits/stdc++.h>
using namespace std;
long long arr[1000001];
long long segtree[4000005];
int n;
long long init(int node, int st, int ed) {
    if(st==ed) return segtree[node]=arr[st];
    return segtree[node]=init(2*node, st, (st+ed)/2)+init(2*node+1, (st+ed)/2+1, ed);
} 
long long get(int node, int st, int ed, int rst, int red) {
    if(st>red || rst>ed) return 0;
    else if(rst<=st && ed<=red) return segtree[node];
    else return get(node*2, st, (st+ed)/2, rst, red)+get(node*2+1, (st+ed)/2+1, ed, rst, red);
}
void update(int node, int st, int ed, int target, long long change) {
    if(st>target||ed<target)return;
    segtree[node]+=change;
    if(st!=ed) {
        update(node*2, st, (st+ed)/2, target, change);
        update(node*2+1, (st+ed)/2+1, ed, target, change);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    long long m, x, y, a, b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>x>>y;
        if(a==2)cout<<get(1, 1, n, x, y)<<'\n';
        else {
            update(1, 1, n, x, y);
        }  

    }
}

