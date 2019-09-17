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

vector<vector<int>> g;

int main()
{
	int n;
	cin>>n;
	g.resize(n);
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> c(n);
	rep(i,n)cin>>c[i];
	sort(all(c));
	reverse(all(c));

	vector<int> num(n,-1);

	num[0] = c[0];

	for (int k = 1; k < n; k++){
		bool flag = false;
		rep(i,n){
			if(num[i]<0) continue;
			rep(j,g[i].size()){
				if(num[g[i][j]]<0){
					num[g[i][j]] = c[k];
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
	}


	cout<<accumulate(c.begin(),c.end(),0)-c[0]<<endl;
	rep(i,n)cout<<num[i]<<" ";
	cout<<endl;


	return 0;
}