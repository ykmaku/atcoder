#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<vector<int>> g;
int dfs(int x){
	if(g[x].size()==0)return 1;
	vector<int> a;
	rep(i,g[x].size()){
		a.push_back(dfs(g[x][i]));
	}
	return *min_element(all(a))+*max_element(all(a))+1;
}

int main()
{
	int n;
	cin>>n;
	g.resize(n+1);
	repi(i,2,n+1){
		int x;
		cin>>x;
		g[x].push_back(i);
	}

	cout<<dfs(1)<<endl;
	return 0;
}