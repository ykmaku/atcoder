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
	int n,m;
	cin>>n>>m;
	vector<vector<P> > g(n,vector<P>());
	vector<vector<int>> dist(n,vector<int>(n,INF));
	for (int i = 0; i < m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		g[a].push_back(P(b,c));
		g[b].push_back(P(a,c));
		dist[a][b] = c;
		dist[b][a] = c;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
			}
		}
	}
	P ans = P(-1,INF);
	for (int i = 0; i < n; i++){
		int res = 0;
		for (int j = 0; j < n; j++){
			if(i==j || dist[i][j] == INF) continue;
			res = max(res,dist[i][j]);
		}
		if(res<ans.second) ans = P(i,res);
	}
	cout<<ans.second<<endl;
	return 0;
}