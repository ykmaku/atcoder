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

using namespace std;

typedef long long int ll;
typedef pair<int,ll> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

vector<vector<P> >g;
vector<int> color;

//この書き方はO(n)ではない
void dfs(int x){
	for(int i = 0; i < g[x].size(); i++){
		if(color[g[x][i].first]<0){
			color[g[x][i].first] = g[x][i].second%2==0?color[x]:abs(color[x]-1);
			dfs(g[x][i].first);
		}
	}
}

int main()
{
	int n;
	cin>>n;
	g.resize(n);
	color.resize(n,-1);
	for(int i = 0; i < n-1; i++){
		ll u,v,w;
		cin>>u>>v>>w;
		u--;
		v--;
		g[u].push_back(P(v,w));
		g[v].push_back(P(u,w));
	}

	color[0] = 0;
	dfs(0);
	for(int i = 0; i < n; i++){
		cout<<color[i]<<endl;
	}

	return 0;
}