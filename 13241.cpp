#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long a,b;
    cin>>a>>b;
    cout<<a*b/gcd(a,b);
}
