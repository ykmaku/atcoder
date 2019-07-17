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

int main()
{
	int n,m;
	cin>>n>>m;
	g.resize(4*n,vector<int>());
	for(int i = 0; i < m; i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b+n);
		g[a+n].push_back(b+2*n);
		g[a+2*n].push_back(b);
	}
	int s,t;
	cin>>s>>t;
	s--;t--;

	vector<ll> dist(4*n,-1);

	queue<ll> q;
	dist[s] = 0;
	q.push(s);
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int i = 0; i < g[p].size(); i++){
			if(dist[g[p][i]] < 0){
				dist[g[p][i]] = dist[p]+1;
				q.push(g[p][i]);
			}
		}
	}

	cout<<(dist[t]%3==0?dist[t]/3:-1)<<endl;

	
	return 0;
}