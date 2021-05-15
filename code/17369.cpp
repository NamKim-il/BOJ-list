#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<pair<ll, ll>> up[300001], down[300001], lef[300001], rig[300001];
vector<pair<ll, ll>>::iterator it;
pair<int,int> arr[300001][4];
ll dir[2][4] = { 4, 3, 2, 1 , 2, 1, 4, 3 }; //1  /거울 2
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll h, w, n, m, a, b, ch;
	char c;
	cin >> h >> w >> n >> m;
	for (ll i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		if (c == '\\') ch = 2;
		else if (c == '/') ch = 1;
		else ch = 0;
		up[b].push_back(make_pair(-a, ch));
		down[b].push_back(make_pair(a, ch));
		lef[a].push_back(make_pair(-b, ch));
		rig[a].push_back(make_pair(b, ch));
	}
	for (ll i = 1; i <= h; i++) {
		sort(lef[i].begin(), lef[i].end());
		sort(rig[i].begin(), rig[i].end());
	}
	for (ll i = 1; i <= w; i++) {
		sort(up[i].begin(), up[i].end());
		sort(down[i].begin(), down[i].end());
	}
	for (ll i = 0; i < m; i++)
	{
		ll nowx, nowy, nowd;
		ll dis = 0, cnt = 0, sum = 0;
		char s;
        int st;
        cin>>s>>st;
        if (s == 'U') {
			nowy = 0; nowx = st;
			nowd = 2;
		}
		else if (s == 'D') {
			nowy = h + 1; nowx = st ;
			nowd = 4;
		}
		else if (s == 'L') {
			nowx = 0; nowy = st ;
			nowd = 1;
		}
		else {
			nowx = w + 1; nowy = st ;
			nowd = 3;
		}
		int st2=st, nowd2=nowd;
		if( arr[st][nowd].first!=0&&arr[st][nowd].second!=0 )  {
			cout<<arr[st][nowd].first-1<<' '<<arr[st][nowd].second-1<<'\n';
			continue;
		}
		while (1)
		{
			if (nowd == 1) { //->
				it = upper_bound(rig[nowy].begin(), rig[nowy].end(), make_pair(nowx, 5ll));
				if (it == rig[nowy].end()) break;
				dis += (*it).first - nowx;
				nowx = (*it).first;
				if ((*it).second)
				{
					nowd = dir[(*it).second - 1][nowd - 1];
				}
				else {
					cnt++; sum += dis;
				}
			}
			else if (nowd == 2) { //down
				it = upper_bound(down[nowx].begin(), down[nowx].end(), make_pair(nowy, 5ll));
				if (it == down[nowx].end()) break;
				dis += ((*it)).first - nowy;
				nowy = ((*it)).first;
				if ((*it).second)
				{
					nowd = dir[(*it).second - 1][nowd - 1];
				}
				else {
					cnt++; sum += dis;
				}
			}
			else if (nowd == 3) { //<-
				it = upper_bound(lef[nowy].begin(), lef[nowy].end(), make_pair(-nowx, 5ll));
				if (it == lef[nowy].end()) break;
				dis += (*it).first + nowx;
				nowx = -(*it).first;
				if ((*it).second)
				{
					nowd = dir[(*it).second - 1][nowd - 1];
				}
				else {
					cnt++; sum += dis;
				}
			}
			else { //up
				it = upper_bound(up[nowx].begin(), up[nowx].end(), make_pair(-nowy, 5ll));
				if (it == up[nowx].end()) break;
				dis += (*it).first + nowy;
				nowy = -(*it).first;
				if ((*it).second)
				{
					nowd = dir[(*it).second - 1][nowd - 1];
				}
				else {
					cnt++; sum += dis;
				}
			}
		}
		//printf("%lld %lld\n", cnt, sum);
		cout << cnt << ' ' << sum << '\n';
		arr[st2][nowd2]={cnt+1,sum+1};
	}
}
