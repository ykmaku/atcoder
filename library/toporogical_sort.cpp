//AOJ GRL_4_B

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
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

// 重みなしグラフ
P toporogical_sort(const vector<vector<int>> g){
	int n = g.size();
	vector<int> in_degree(n,0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < g[i].size(); j++){
			in_degree[g[i][j]]++;
		}
	}

	vector<int> res,length(n);
	stack<int> S;
	for(int i = 0; i < n; i++){
		if(in_degree[i]==0) S.push(i),length[i]=0;
	}

	while(!S.empty()){
		int p = S.top();
		S.pop();
		res.push_back(p);
		for(int i = 0; i < g[p].size(); i++){
			in_degree[g[p][i]]--;
			if(in_degree[g[p][i]]==0) S.push(g[p][i]),length[g[p][i]]=length[p]+1;
		}
	}

	//res.size()==nならばgはDAG
	//resはトポロジカルソートされた頂点列
	//*max_element(all(length))はgの最長パスの長さ
	if(res.empty() || res.size()!=n){
		return P(-1,-1);
	}else{
		vector<int> dp(n,0);
		rep(i,n){
			int p = res[i];
			rep(j,g[p].size()){
				dp[g[p][j]] = max(dp[g[p][j]],dp[p]+1);
			}
		}

		return P(n,*max_element(all(dp)));
	}

}

int main()
{
	int V,E;
	cin>>V>>E;
	vector<vector<int> > g(V,vector<int>());
	for(int i = 0; i < E; i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
	}

	vector<int> t_sort = toporogical_sort(g);
	for(int i = 0; i < t_sort.size(); i++){
		cout << t_sort[i] << endl;
	}

	return 0;
}