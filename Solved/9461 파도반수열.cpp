#include<iostream>
using namespace std;
int main(){
    long long t,n,i,a[101];
    a[1]=1;
    a[2]=1;
    a[3]=1;
    a[4]=2;
    a[5]=2;
    for(i=6;i<=100;i++)
        a[i]=a[i-1]+a[i-5];
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        cout<<a[n]<<endl;
    }


}
