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
typedef pair<int,ll> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<vector<int>> g;
vector<ll> node,flag;

void dfs(int x,int cnt){
	flag[x] = true;
	for (int i = 0; i < g[x].size(); i++){
		int next = g[x][i];
		if(!flag[next]){
			node[next] += cnt;
			dfs(next,node[next]);
		}
	}

	return;
}

int main()
{
	int n,q;
	cin>>n>>q;
	g.resize(n,vector<int>());
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--,b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<P> query(q);
	rep(i,q){
		cin>>query[i].first>>query[i].second;
		query[i].first--;
	}
	node.resize(n,0);
	flag.resize(n);
	rep(i,q) node[query[i].first] += query[i].second;

	dfs(0,node[0]);

	rep(i,n)cout<<node[i]<<" ";
	cout<<endl;

	return 0;
}