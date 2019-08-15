#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	int r,c;
	cin>>r>>c;
	int sx,sy,gx,gy;
	cin>>sy>>sx>>gy>>gx;
	sy--;sx--;gy--;gx--;
	vector<string> s(r);
	for (int i = 0; i < r; i++){
		cin>>s[i];
	}

	vector<vector<int> > ans(r,vector<int>(c,0));
	queue<P> que;
	que.push(P(sx,sy));
	while(!que.empty()){
		P p = que.front();que.pop();
		int x = p.first;
		int y = p.second;
		int step = ans[y][x];
		for (int i = 0; i < 4; i++){
			if(0<=x+dx[i] && x+dx[i]<c && 0<=y+dy[i] && y+dy[i]<r && s[y+dy[i]][x+dx[i]]!='#' && ans[y+dy[i]][x+dx[i]]==0){
				ans[y+dy[i]][x+dx[i]] = step+1;
				que.push(P(x+dx[i],y+dy[i]));
			}
		}
	}
	cout<<ans[gy][gx]<<endl;
	return 0;
}