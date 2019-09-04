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

vector<vector<P> > g;

void dfs(int x, int len){

}

int main()
{
	int n;
	cin>>n;
	bool is_even = true;
	// if(n%2!=0){
	// 	n--;
	// 	is_even=false;
	// }
	g.resize(n,vector<P>());
	rep(i,n){
		rep(j,n){
			g[i].push_back(P(j,-1));
			g[j].push_back(P(j,-1));
		}
		g[i][i] = P(i,1);
	}

	vector<vector<int> > ans(n,vector<int>(n,-1));

	int level = (is_even?1:2);
	rep(i,n){
		vector<int> used(n,-1);
		rep(i,n){
			rep(j,n){
				if(g[i][j].second<0){
					if(used[i]<0 || used[j]<0){
						used[i] = 1;
						used[j] = 1;
						g[i][j].second = 1;
						g[j][i].second = 1;
						ans[i][j] = level;
						ans[j][i] = level;
					}
				}
			}
		}
		level++;
	}
	if(!is_even){
		rep(i,n+1) cout<<1<<endl;
	}
	for (int i = 0; i < n-1; i++){
		for (int j = i+1; j < n; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	// rep(i,n){
	// 	rep(j,n){
	// 		cout<<ans[i][j]<<" ";
	// 	}cout<<endl;
	// }
	return 0;
}