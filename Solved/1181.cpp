#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<pair<int, string>> v;
    cin>>n;
    for(int i=0;i<n;i++) {
        pair<int, string> p;
        cin>>p.second;
        p.first=p.second.size();
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    string bef="";
    for(auto i : v) {
        if(bef==i.second) continue;
        cout<<i.second<<'\n';
        bef=i.second;
    }
}