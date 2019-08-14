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

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


vector<vector<P> > g;

bool has_positive_cycle(int target,int pos,vector<int> flag,int cost){
	flag[pos]++;
	for (int i = 0; i < g[pos].size(); i++){
		int x = g[pos][i].first;
		if(x==target){
			return cost+g[pos][i].second>0;
		}
		if(flag[x]<0){
			return has_positive_cycle(target,x,flag,cost+g[pos][i].second);
		}
	}
	return false;
}

bool go_target(int target,int pos,vector<int> flag){
	flag[pos]++;
	for (int i = 0; i < g[pos].size(); i++){
		int x = g[pos][i].first;
		if(x==target){
			return true;
		}
		if(flag[x]<0){
			return go_target(target,x,flag);
		}
	}
	return false;
}




int main()
{
	int n,m,p;
	cin>>n>>m>>p;
	g.resize(n);
	for (int i = 0; i < m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		c = c-p;
		g[a].push_back(P(b,c));
	}

	// for (int i = 1; i < n-1; i++){
	// 	vector<int> flag1(n,-1),flag2(n,-1);
	// 	if(!go_target(i,0,flag1) || !go_target(i,n-1,flag2)){
	// 		for (int j = 0; j < g[i].size(); j++){
	// 			g[i][j].second= 0;
	// 		}
	// 	}
	// }

	// for (int i = 0; i < n; i++){
	// 	vector<int> flag(n,-1);
	// 	if(has_positive_cycle(i,i,flag,0)){
	// 		cout<<-1<<endl;
	// 		return 0;
	// 	}
	// }

	for (int i = 0; i < n; i++){
		for (int j = 0; j < g[i].size(); j++){
			g[i][j].second *= -1;
		}
	}
	int ret = 1e9;
	vector<int> dist(n,1e9);
	dist[0] = 0;
	vector<bool> update(n,false);
	for(int k = 0;k < n*2;k++){
		for(int i = 0;i < n; i++)update[i] = false;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < g[i].size(); j++){
				int to = g[i][j].first;
				int cost = g[i][j].second;
				if(dist[i]!=1e9 && dist[to] > dist[i] + cost){
					dist[to] = dist[i] + cost;
					if(k>=n) update[to] = true;
				}
			}
			// if(update){
			// 	// cout<<dist[n-1]<<endl;
			// 	if(k>=n && dist[n-1]<ret){
			// 		cout<<-1<<endl;
			// 		return 0;
			// 	}
			// 	ret = dist[n-1];
			// 	// break;
			// }
		}
		if(k>=n){
			for (int i = 0; i < n; i++){
				if(update[i]){
					for (int j = 0; j < g[i].size(); j++){
						update[g[i][j].first] = true;
					}
				}
			}
			if(update[n-1]){
				cout<<-1<<endl;
				return 0;
			}
		}
	}

	cout<<max(0,-1*dist[n-1]) << endl;


	return 0;
}
