#include<bits/stdc++.h>
using namespace std;
long long arr[1000005],ans[1000005];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long n,m,k,j,d,a,b;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        j=i;
        while(j<=n)
        {
            ans[j]+=arr[i];
            j+=j&(-j);
        }
    }
    for(int i=0;i<m+k;i++)
    {
        cin>>d>>a>>b;
        if(d==1){
            j=a;
            while(j<=n){
                ans[j]+=(b-arr[a]);
                j+=j&-j;
            }
            arr[a]=b;
        }
        else {
            long long answer=0;
            a--;
            while(a>0){
                answer-=ans[a];
                a-=a&-a;
            }
            while(b>0){
                answer+=ans[b];
                b-=b&-b;
            }

            cout<<answer<<"\n";
        }
    }
}
