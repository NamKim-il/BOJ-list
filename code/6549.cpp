#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[100002];
vector<int>  seg;
int n;
ll init(int node, int st, int ed)
{
    if(st==ed) return seg[node]=st;
    int l=init(node*2, st, (st+ed)/2);
    int r=init(node*2+1, (st+ed)/2+1, ed);
    return seg[node]= arr[l]>arr[r] ? r : l;
}
ll min_(int node, int st, int ed, int sm, int big)
{
    if(st>big || ed<sm) return 100001;
    if(sm<=st&&ed<=big) return seg[node];

    int l = min_(node * 2, st, (st + ed) / 2, sm, big);
    int r = min_(node * 2 + 1, (st + ed) / 2 + 1, ed, sm, big);
    return arr[l] > arr[r] ? r : l;
}
ll solve(int st, int ed)
{
    ll minp=min_(1, 1, n, st, ed);
    if(st==ed) return arr[st];
    ll ret=(ll)arr[minp]*(ed-st+1);
    if(minp-1>=st) {
        ret=max(ret, solve(st, minp-1));
    }
    if(minp+1<=ed) {
        ret=max(ret, solve(minp+1, ed));
    }
    return ret;
}
int main()
{
        arr[100001] = 2e9;
    while(1)
    {
        cin>>n;
        if(!n) break;
        //arr.resize(n+1);
        for(int i=1;i<=n;i++) cin>>arr[i];
        int segsize=(int)ceil(log2(n))+1;
        seg.resize(1<<segsize);
        init(1, 1, n);
        cout<<solve(1, n)<<'\n';
    }
}
