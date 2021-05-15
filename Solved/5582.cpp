#include<bits/stdc++.h>
using namespace std;
int arr[4000][4000];
int main()
{
    string s1, s2;
    cin>>s1>>s2;
    int len1=s1.size(), len2=s2.size(), ans=0;
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            if(i*j==0) {
                if(s1[i]==s2[j]) arr[i][j]=1;
            }
            else {
                if(s1[i]==s2[j]) arr[i][j]=arr[i-1][j-1]+1;
            }
            ans=max(ans, arr[i][j]);
        }
    }
    cout<<ans;

}
