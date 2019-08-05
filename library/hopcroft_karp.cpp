#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

class hopcroft_karp{
public:
	vector<vector<int> > graph; //linked list
	vector<int> dist,match;
	vector<bool> used,vv;

	hopcroft_karp(int n,int m) : graph(n),match(m,-1),used(n) {}

	void add_edge(int u,int v){
		graph[u].push_back(v);
	}

	//層グラフ作り
	void bfs(){
		dist.assign(graph.size(),-1);
		queue<int> que;
		for(int i = 0; i < graph.size(); i++){
			if (!used[i]){
				que.push(i);
				dist[i] = 0;
			}
		}

		while(!que.empty()){
			int a = que.front();
			que.pop();
			for(int i = 0 ; i < graph[a].size(); i++){
				int b = graph[a][i];
				int c = match[b];
				if(c >= 0 && dist[c] == -1){
					dist[c] = dist[a]+1;
					que.push(c);
				}
			}
		}
	}

	bool dfs(int a){
		vv[a] = true;
		for(int i = 0; i < graph[a].size(); i++){
			int b = graph[a][i];
			int c = match[b];
			if(c < 0 || (!vv[c] && dist[c] == dist[a]+1　&& dfs(c))){
				match[b] = a;
				used[a] = true;
				return true;
			}
		}
		return false;
	}

	int bipartite_matching(){
		int ret = 0;
		while(1){
			bfs();
			vv.assign(graph.size(),false);
			int flow = 0;
			for(int i = 0; i < graph.size(); i++){
				if(!used[i] && dfs(i)) flow++;
			}
			if(flow == 0) return ret;
			ret += flow;
		}
	}

	void output(){
		for(int i = 0; i < match.size(); i++){
			if (~match[i]){
				cout << match[i] << " " << i << endl;
			}
		}
	}
};

int main()  //AOJ_ GRL_7_A
{
	int X,Y,E;
	cin >> X >> Y >> E;
	hopcroft_karp g(X,Y);
	for(int i = 0; i < E; i++){
		int a,b;
		cin >> a >> b;
		g.add_edge(a,b);
	}

	cout << g.bipartite_matching() << endl;

	return 0;
}