#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int round,cases,i,n,m,k,count;

    cin>>cases;
    for(round=0;round<cases;round++)
    {
        count=0;
        queue< pair<int,int> > c;
        priority_queue<int> pr;
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>k;
            c.push(make_pair(k,i));
            pr.push(k);
        }
        while(1){
            if(pr.top()==c.front().first){
                if(c.front().second==m)
                    break;
                pr.pop();
                c.pop();
                count++;
            }
            else {
                c.push(c.front());
                c.pop();
            }

        }
        cout<<count+1<<endl;




    }
}
