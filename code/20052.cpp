#include<bits/stdc++.h>
using namespace std;

int n;
pair<int,int> arr[100005];
pair<int,int> seg[400005];

pair<int,int> add(pair<int,int> fr, pair<int, int> bk) 
{
 if(fr.second>bk.first) {
        return {fr.first, bk.second+fr.second-bk.first};
    }
    else {
        return {fr.first-fr.second+bk.first, bk.second};
    }
}

pair<int,int> init(int node, int st, int ed) 
{
    if(st==ed) return seg[node]=arr[st];
    pair<int,int> fr=init(node*2, st, (st+ed)/2);
    pair<int,int> bk=init(node*2+1, (st+ed)/2+1, ed);
    return seg[node]=add(fr, bk);
}

pair<int,int> check(int node, int st, int ed, int fr, int bk) {
    if(st>bk || ed<fr) return {0,0};
    if(fr<=st && ed<=bk) return seg[node];
    pair<int,int> tmp=add(check(node*2, st, (st+ed)/2, fr, bk), check(node*2+1, (st+ed)/2+1, ed, fr, bk));
    return tmp;
}


int main()
{
    string s;
    cin>>s;
    n=s.size();
    for(int i=0;i<s.size();i++) {
        if(s[i]==')') arr[i+1]={1, 0};
        else arr[i+1]={0, 1};
    }
    init(1, 1, n);
    int tc, cnt=0;
    cin>>tc;
    while(tc--) {
        int x, y;
        cin>>x>>y;
        if(check(1, 1, n, x, y)==make_pair(0,0)) {
            cnt++;
        }
    }
    cout<<cnt;
    
}