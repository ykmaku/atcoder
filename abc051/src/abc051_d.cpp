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

struct edge{
	int from,to,cost;
	edge(int f,int t,int c){from=f,to=t,cost=c;};
};

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n,vector<int>(n,1e9+10));
	for (int i = 0; i < n; i++){
		g[i][i] = 0;
	}
	for (int i = 0; i < m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		g[a][b] = c;
		g[b][a] = c;
	}

	vector<vector<int> >  dist(n,vector<int>(n,1e9+10));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			dist[i][j] = g[i][j];
		}
	}
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			if(dist[i][j] < g[i][j] && g[i][j]<1e9+10) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}