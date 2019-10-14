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
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}

int main()
{
	int n,a,b,m;
	cin>>n>>a>>b>>m;
	a--;b--;
	vector<vector<int>> g(n,vector<int>());
	rep(i,m){
		int x,y;
		cin>>x>>y;
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	queue<int> que;
	vector<int> dist(n,-1),cnt(n,0),used(n,0);
	dist[a]=0;
	cnt[a]=1;
	que.push(a);
	while(!que.empty()){
		int x=que.front();que.pop();
		used[x]=1;
		for(auto p:g[x]){
			if(used[p]>0)continue;
			if(dist[p]<0){
				dist[p]=dist[x]+1;
				cnt[p]+=cnt[x];
				cnt[p]%=mod;
				que.push(p);
				continue;
			}
			if(dist[p]==dist[x]+1){
				cnt[p]+=cnt[x];
				cnt[p]%=mod;
			}
		}
	}


	cout<<cnt[b]<<endl;
	return 0;
}