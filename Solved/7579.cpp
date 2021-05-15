#include<bits/stdc++.h>
using namespace std;
int mem[100], cost[100];
int dp[100][10001];
int n, m, MIN=10000;
int main()
{
    cin>>n>>m;
    int selmp=0;
    for(int i=0;i<n;i++) cin>>mem[i];
    for(int i=0;i<n;i++) cin>>cost[i];
    for(int i=0;i<n;i++) {
        if(!i) dp[i][cost[i]]=mem[i];
        else {
            for(int j=0;j<=10000;j++) {
                if(j<cost[i]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j-cost[i]]+mem[i], dp[i-1][j]);
            }
        }
    }
    for(int i=0;i<=10000;i++) {
        if(dp[n-1][i]>=m) MIN=min(MIN, i);
    }
    cout<<MIN;
}  