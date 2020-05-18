#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}
ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}

vector<vector<int>> g;
vector<int> pred;

int main()
{
	int n, m;
	cin>>n>>m;
	g.resize(n);
	pred.resize(n,-1);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}

	queue<int> que;
	que.push(0);
	while(!que.empty()){
		int now = que.front();que.pop();
		for(auto x:g[now]){
			if(pred[x]>=0)continue;
			pred[x] = now;
			que.push(x);
		}
	}

	cout<<"Yes"<<endl;
	repi(i,1,n){
		cout<<pred[i] + 1<<endl;
	}

	return 0;
}