 #include<iostream>
 using namespace std;
 int a[1005];
 int main()
 {
     int n,i,j;
     a[0]=1;
     a[1]=1;
     a[2]=3;
     for(i=3;i<1003;i++)
        a[i]=(a[i-1]+a[i-2]*2)%10007;
    cin>>n;
    cout<<a[n];

 }
