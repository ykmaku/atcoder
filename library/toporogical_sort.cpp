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

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

vector<int> toporogical_sort(const vector<vector<int> > g){
	int n = g.size();
	vector<int> in_degree(n,0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < g[i].size(); j++){
			in_degree[g[i][j]]++;
		}
	}

	vector<int> res;
	stack<int> S;
	for(int i = 0; i < n; i++){
		if(in_degree[i]==0) S.push(i);
	}

	while(!S.empty()){
		int p = S.top();
		S.pop();
		res.push_back(p);
		for(int i = 0; i < g[p].size(); i++){
			in_degree[g[p][i]]--;
			if(in_degree[g[p][i]]==0) S.push(g[p][i]);
		}
	}

	return res;
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