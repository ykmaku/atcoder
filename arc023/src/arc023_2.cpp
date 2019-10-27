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

int main()
{
	int r,c,d;
	cin>>r>>c>>d;
	vector<vector<int>> a(r,vector<int>(c)),dist(r,vector<int>(c));
	rep(i,r)rep(j,c)cin>>a[i][j],dist[i][j]=i+j;

	int ans=0;
	rep(i,r)rep(j,c){
		if(d%2==0&&dist[i][j]%2==0&&dist[i][j]<=d)ans=max(ans,a[i][j]);
		else if(d%2!=0&&dist[i][j]%2!=0&&dist[i][j]<=d)ans=max(ans,a[i][j]);
	}
	cout<<ans<<endl;
	return 0;
}