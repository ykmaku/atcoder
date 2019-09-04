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

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

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
			if(c < 0 || (!vv[c] && dist[c] == dist[a]+1 && dfs(c))){
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
	int n;
	cin>>n;
	vector<P> red(n),blue(n);
	rep(i,n){
		int a,b;
		cin>>a>>b;
		// a--,b--;
		red[i] = P(a,b);
	}
	rep(i,n){
		int a,b;
		cin>>a>>b;
		// a--,b--;
		blue[i] = P(a,b);
	}

	hopcroft_karp g(n,n);

	rep(i,n){
		rep(j,n){
			if(red[i].first < blue[j].first && red[i].second<blue[j].second) g.add_edge(i,j);
		}
	}

	cout << g.bipartite_matching() << endl;

	return 0;
}

