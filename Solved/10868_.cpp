#include<bits/stdc++.h>
#define ll long long
#define MAX 10000000000
using namespace std;
ll arr[1000005];
vector<ll> tree(4000005);
ll init(ll nod, ll st, ll en)
{
    if(st==en) return tree[nod]=arr[st];
    else return tree[nod]=min(init(2*nod,st,(st+en)/2),init(2*nod+1,(st+en)/2+1,en));
}
/*
void update(ll add,ll nod, ll st, ll en, ll i, ll j)
{
    if(st>j||en<i) return;
    if(i<=st&&j>=en) {
        tree[nod]+=add*(en-st+1);
        if(st!=en) {
            tree[nod*2].lazy+=add;
            tree[nod*2+1].lazy+=add;
        }
        return;
    }
    update(add,nod*2,st,(st+en)/2,i,j);
    update(add,nod*2+1,(st+en)/2+1,en,i,j);
    tree[nod]=min(tree[nod*2],tree[nod*2+1]);
}
*/
ll ans(ll nod,ll st, ll en,ll i,ll j){
    if(st>j||en<i) return MAX;
    if(i<=st&&j>=en) {
        return tree[nod];
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
        cout<<ans(1,1,N,a,b)<<"\n";
    }

}
