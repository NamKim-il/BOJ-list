#include<bits/stdc++.h>
#define ll long long
using namespace std;
int N,M,K;
typedef struct node{
    ll data,lazy;
    bool ch;
}node;
vector<node> tree;
void make(int a);
ll make_tree(int i)
{

    i-=-1;
    int tmp=(i&-i)>>1;
    if(tree[i-1].ch) return tree[i-1].data;
    else{
        make(i-1-tmp);
        make(i-1+tmp);
        return tree[i-tmp-1].data+tree[i+tmp-1].data;
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    ll a,b,c,i;
    cin>>N>>M>>K;
    for(i=0;i<N;i++)
    {
        cin>>a;
        node tmp={a,0,true},tmp2={0,0,false};
        tree.push_back(tmp);
        tree.push_back(tmp2);

    }
    int k=1;
    while((N*2)/k>=2) k*=2;
    for(;i<k;i++)
    {
        node tmp={0,0,true},tmp2={0,0,false};
        tree.push_back(tmp);
        tree.push_back(tmp2);
    }
    make(k-1);
    for(i=0;i<2*N-1;i++)
    {
        cout<<tree[i].data<<endl;
    }
}
void make(int a)
{
    tree[a].data=make_tree(a);
    tree[a].ch=true;
}
