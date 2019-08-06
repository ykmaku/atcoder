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

int main()
{
	int n;
	cin>>n;
	vector<vector<int> > d(n,vector<int>(n,0));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin>>d[i][j];
		}
	}
	int q;
	cin>>q;
	vector<int> p(q);
	for (int i = 0; i < q; i++){
		cin>>p[i];
	}

	vector<vector<int> > sum(n+1,vector<int>(n+1,0));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			sum[i][j] = sum[i][j-1]+sum[i-1][j] - sum[i-1][j-1] + d[i-1][j-1];
		}
	}

	vector<int> cnt(2510,0);
	for (int xs = 1; xs <= n; xs++){
		for (int xl = xs; xl <= n; xl++){
			for (int ys = 1; ys <= n; ys++){
				for (int yl = ys; yl <= n; yl++){
					int res = sum[xl][yl] - sum[xl][ys-1] - sum[xs-1][yl] + sum[xs-1][ys-1];
					cnt[(xl-xs+1)*(yl-ys+1)] = max(cnt[(xl-xs+1)*(yl-ys+1)],res);
				}
			}
		}
	}

	for (int i = 0; i < cnt.size(); i++){
		cnt[i] = max(cnt[i],cnt[i-1]);
	}

	for(auto x:p) cout<<cnt[x]<<endl;

	return 0;
}