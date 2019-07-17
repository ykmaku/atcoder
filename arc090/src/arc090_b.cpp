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
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

vector<vector<int> > g;
vector<vector<P> > edge; //vertex,cost
vector<int> dist,used;
bool flag;

void dfs(int x){
	if(used[x]) return;
	used[x]++;
	for(auto p : edge[x]){
		int to = p.first;
		int cost = p.second;
		if(!used[to]){
			dist[to] = dist[x] + cost;
			dfs(to);
		}else if(dist[to] - dist[x] != cost){
			flag = false;
			return;
		}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	g.resize(n,vector<int>());
	edge.resize(n,vector<P>());
	dist.resize(n,-1);
	used.resize(n,0);
	flag=true;
	for (int i = 0; i < m; i++)
	{
		int l,r,d;
		cin>>l>>r>>d;
		l--;
		r--;
		g[l].push_back(r);
		g[r].push_back(l);
		edge[l].push_back(P(r,d));
		edge[r].push_back(P(l,-d));
	}
	for (int i = 0; i < n; i++){
		if(!flag)break;
		if(dist[i] < 0){
			dist[i] = 0;
			dfs(i);
		}
	}
	cout<<(flag?"Yes":"No")<<endl;


	return 0;
}