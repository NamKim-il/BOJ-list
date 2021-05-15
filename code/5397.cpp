#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n-->0)
    {
        string s;
        cin>>s;
        int len=s.length(),i;
        vector<char> pass;
        auto it=pass.begin();
        for(i=0;i<len;i++)
        {
            if(s[i]=='<')
                if(it>pass.begin())
                    it--;
            else if(s[i]=='>')
                if(it<pass.end()) it++;
            else{
                pass.insert(it,s[i]);
                it++;
            }
        }
        it=pass.begin();
        while(it<pass.end()) cout<<*it;
    }
}
