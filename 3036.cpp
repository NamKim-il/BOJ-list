#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,d,x;
    cin>>n;
    cin>>x;
    while(n-->1)
    {
        cin>>d;
        cout<<(x/gcd(x,d))<<'/'<<(d/gcd(x,d))<<endl;
    }

}
