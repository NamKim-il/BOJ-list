#include<bits/stdc++.h>
using namespace std;
int a[500001][2];
int b[1000001][2];
bool check[500001][2];
vector<int> treeup(2000001);
vector<int> treedown(2000001);
int sum;
int init(int now, int st, int en)
{
    if(st==en) return treeup[now]=1;
    else return treeup[now]=init(now*2,st,(st+en)/2)+init(now*2+1,(st+en)/2,en);
}
int initdown(int now, int st, int en)
{
    if(st==en) return treedown[now]=1;
    else return treedown[now]=initdown(now*2,st,(st+en)/2)+initdown(now*2+1,(st+en)/2,en);
}
void update(int now, int st, int en, int k)
{

}
void downdate(int  now, int st, int en, int k)
{

}
int sumtree(int now, int st, int en, int i, int j, int tmp)
{
    if(en<i||st>j) return 0;
    if(i<=st&&en<=j)
    {
        if(tmp==1) return treeup(now);
        else return treedown(now);
    }
    return sumtree(now*2,st,(st+en)/2,i,j,tmp)+sumtree(now*2+1,(st+en)/2+1,en,i,j,tmp);
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,i;
    cin>>n;
    for(i=0;i<2*n;i++)
    {
        cin>>a[i+1][i/n];
        b[a[i+1][i/n]][1-i/n]=i%n+1;
    }
    for(i=0;i<2*n;i++)
    {
        a[i+1][i/n]=b[a[i+1][i/n]][i/n];
    }
    init(1,1,n);
    initdown(1,1,n);
    for(i=1;i<=n;i++)
    {

    }
}
