#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long arr[1000005], segt[4000005];

long long init(int node, int st, int ed) {
    if(st==ed) return segt[node]=arr[st]%MOD;
    else {
        return segt[node]=init(node*2, st, (st+ed)/2)*init(node*2+1, (st+ed)/2+1, ed)%MOD;
    }
}
void update(int node, int st, int ed, int target, int up) {
    if(st>target || ed<target) return;
    else if(st==ed) {
        segt[node]=up;
    }
    else {
        update(node*2, st, (st+ed)/2, target, up);
        update(node*2+1, (st+ed)/2+1, ed, target, up);
        segt[node]=segt[node*2]*segt[node*2+1]%MOD;
    }
}
long long get(int node, int st, int ed, int rst, int red)
{
    if(st>red||ed<rst) return 1;
    else if(rst<=st && ed<=red) return segt[node];
    else return get(node*2, st, (st+ed)/2, rst, red)*get(node*2+1, (st+ed)/2+1, ed, rst, red)%MOD;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    int n, m, k, a, b, c;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    init(1, 1, n);
    for(int j=0;j<m+k;j++) {
        cin>>a>>b>>c;
        if(a==1) {
            update(1, 1, n, b, c);
        }
        else cout<<get(1, 1, n, b, c)<<'\n';
    }


}