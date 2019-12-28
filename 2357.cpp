#include<bits/stdc++.h>
#define ll long long
#define MAX 10000000000
#define MIN 0
using namespace std;
typedef struct node{
    ll min, max;
}node;
ll arr[1000005];
vector<node> tree(4000005);
node init(ll nod, ll st, ll en)
{
    if(st==en){
        tree[nod].min=arr[st];
        tree[nod].max=arr[st];
        return tree[nod];
    }
    else {
        node a=init(2*nod,st,(st+en)/2);
        node b=init(2*nod+1,(st+en)/2+1,en);
        tree[nod].min=min(a.min,b.min);
        tree[nod].max=max(a.max,b.max);
        return tree[nod];
    }
}
ll ans_max(ll nod, ll st, ll en, ll i, ll j)
{
    if(st>j||en<i) return MIN;
    if(i<=st&&j>=en) {
        return tree[nod].max;
    }
    return max(ans_max(nod*2,st,(st+en)/2,i,j),ans_max(nod*2+1,(st+en)/2+1,en,i,j));
}

ll ans(ll nod,ll st, ll en,ll i,ll j){
    if(st>j||en<i) return MAX;
    if(i<=st&&j>=en) {
        return tree[nod].min;
    }
    return min(ans(nod*2,st,(st+en)/2,i,j),ans(nod*2+1,(st+en)/2+1,en,i,j));
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    ll N,M,K,a,b,d,i;
    ll c;
    cin>>N>>M;
    for(i=1;i<=N;i++) {
        cin>>arr[i];
    }
    init(1,1,N);
    for(i=0;i<M ;i++)
    {
        cin>>a>>b;
        cout<<ans(1,1,N,a,b)<<' '<<ans_max(1,1,N,a,b)<<"\n";
    }

}
