#include"bits/stdc++.h"

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("./input.txt", "r", stdin);
    int tc;
    int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
    cin>>tc;
    while(tc--)
    {
        int h, w;
        int ans=1e9;
        cin>>h>>w;
        string s[101];
        for(int i=1;i<=h;i++) {
            cin>>s[i];
        }
        int mp[102][102]={};
        stack<pair<int,int>> st;
        st.push({0,0});
        for(int i=0;i<=h+1;i++) {
            for(int j=0;j<=w+1;j++) {
                if(i==0||j==0||i==h+1||j==w+1||s[i][j-1]=='.') {
                    mp[i][j]=0;
                }
                else if(s[i][j-1]=='*') {
                    mp[i][j]=1e8;
                }
                else if(s[i][j-1]=='#') {
                    mp[i][j]=1;
                }
                else st.push({i,j});
            }
        }
        int count[3][102][102]={}, tmp=0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
        while(!st.empty()) {
            q.push({1,st.top()});
            count[tmp][st.top().first][st.top().second]=1;
            st.pop();
            while(!q.empty()) {
                int dis=q.top().first, nowy=q.top().second.first, nowx=q.top().second.second; q.pop();
                for(int i=0;i<4;i++) {
                    int ny=nowy+dy[i], nx=nowx+dx[i];
                    if(nx<0||ny<0||nx>w+1||ny>h+1) continue;
                    if(!count[tmp][ny][nx]) {
                        if(mp[ny][nx]==1e8) {
                            count[tmp][ny][nx]=1e8;
                            continue;
                        }
                        else  count[tmp][ny][nx]=dis+mp[ny][nx];
                        q.push({count[tmp][ny][nx],{ny,nx}});
                    }
                }
            }
            tmp++;
        }
        for(int i=0;i<=h+1;i++) {
            for(int j=0;j<=w+1;j++) {
                if(mp[i][j]<2&&count[0][i][j]&&count[1][i][j]&&count[2][i][j]) {
                    ans=min(ans, count[0][i][j]+count[1][i][j]+count[2][i][j]-2*mp[i][j]-3);
                }
                //printf("%10d",count[0][i][j]);
            }
            //cout<<endl;
        }
       
        cout<<ans<<'\n';
        
    }   
  
    
}
