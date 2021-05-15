#include<iostream>
using namespace std;
int main()
{
    long long a[100],i,j;
    a[0]=1;
    a[1]=1;
    a[2]=1;
    for(i=3;i<100;i++)
    {
        a[i]=0;
        for(j=i-2;j>=0;j--)
            a[i]+=a[j];
    }
    cin>>i;
    cout<<a[i];
}
