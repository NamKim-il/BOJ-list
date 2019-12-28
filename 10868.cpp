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
void change(ll ch,ll nod, ll st, ll en,ll i)
{
    if(i<st||en<i) return;
    if(st==en){
        tree[nod]=ch;
        return;
    }
    change(ch,nod*2,st,(st+en)/2,i);
    change(ch,nod*2+1,(st+en)/2+1,en,i);
}
ll update(ll nod, ll st, ll en,ll i)
{
    if(st==en) return tree[nod];
    else if(st<=i&&i<=en) return tree[nod]=min(update(nod*2,st,(st+en)/2,i),update(nod*2+1,(st+en)/2+1,en,i));
    else return tree[nod];

}
ll ans(ll nod,ll st, ll en,ll i,ll j){
    if(st>j||en<i) return MAX;
    if(i<=st&&j>=en) {
        return tree[nod];
    }
    else return min(ans(nod*2,st,(st+en)/2,i,j),ans(nod*2+1,(st+en)/2+1,en,i,j));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N,M,K,a,b,c,i;
    cin>>N;
    for(i=1;i<=N;i++) {
        cin>>arr[i];
    }
    init(1,1,N);
    cin>>M;
    for(i=0;i<M ;i++)
    {
        cin>>a>>b>>c;
        if(a==2)
            cout<<ans(1,1,N,b,c)<<"\n";
        else {
            change(c,1,1,N,b);
            update(1,1,N,b);
        }
    }

}
