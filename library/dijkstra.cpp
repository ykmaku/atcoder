//AOJ ALDS1_12_B dijkstra法 2018/9/20

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;
typedef pair<int, int> P;  //firstは最短距離,secondは頂点番号

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

struct edge{
	int to,cost;
	edge(){to=0;cost=0;}
};

class dijkstra{
public:
	vector<vector<edge> > E;
	vector<int> dist;
	int start;
	dijkstra(int n): E(n),dist(n){}

	void add_edge(int x,int y,int c){
		edge e;
		e.to = y,e.cost = c;
		E[x].push_back(e);
	}

	void shortest_path(){
		priority_queue<P,vector<P>,greater<P> > que;
		dist.assign(dist.size(),INF);

		dist[start] = 0;
		que.push(P(0,start));

		while(!que.empty()){
			 P p = que.top();
			 que.pop();
			 int v = p.second;
			 if(dist[v] < p.first) continue;

			 for(int i = 0; i < E[v].size(); i++){
			 	edge e = E[v][i];
			 	if(dist[v] +  e.cost < dist[e.to]){
			 		dist[e.to] = dist[v] +  e.cost;
			 		que.push(P(dist[e.to],e.to));
			 	}
			 }
		}
	}


};

int main()
{
	int n;
	cin >> n;
	dijkstra dij(n);
	for(int i = 0; i < n; i++){
		int u,k;
		cin >> u >> k;
		for(int j = 0; j < k; j++){
			int v,c;
			cin >> v >> c;
			dij.add_edge(u,v,c);
		}
	}

	dij.start = 0;
	dij.shortest_path();

	for(int i = 0; i < n; i++){
		cout << i << " " <<  dij.dist[i] << endl;
	}

	return 0;
}