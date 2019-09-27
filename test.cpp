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

int main()
{
	int r,c;
	cin>>r>>c;
	vector<string> s(r);
	rep(i,r)cin>>s[i];
	int cnt = 0;
	rep(i,r){
		rep(j,c){
			if(s[i][j]=='.')cnt++;
		}
	}

	hopcroft_karp hk((r*c+1)/2,r*c/2);

	int parity=1;
	rep(i,r){
		for (int j = (parity>0?0:1); j < c; j+=2){
			if(s[i][j]=='*')continue;
			rep(k,4){
				if(0<=i+dy[k]&&i+dy[k]<r&&0<=j+dx[k]&&j+dx[k]<c){
					if(s[i+dy[k]][j+dx[k]]=='.'){
						int u = (i*c+j)/2;
						int v = ((i+dy[k])*c+(j+dx[k]))/2;
						// cout<<"add "<<u<<" "<<v<<endl;
						hk.add_edge(u,v);
					}
				}
			}
		}
		parity *= -1;
	}

	cout<<cnt-hk.bipartite_matching()<<endl;

	return 0;
}