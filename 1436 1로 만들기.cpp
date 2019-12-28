#include<iostream>
using namespace std;
int a[1000005];
int main()
{
    a[1]=0;
    a[2]=1;
    int n,min;
    cin>>n;
    for(int i=3;i<=n;i++)
    {
        min=a[i-1]+1;
        if(i%3==0){
            if(min>a[i/3]+1)
                min=a[i/3]+1;
        }
        if(i%2==0){
            if(min>a[i/2]+1)
                min=a[i/2]+1;
        }
        a[i]=min;
    }
    cout<<a[n];
}
