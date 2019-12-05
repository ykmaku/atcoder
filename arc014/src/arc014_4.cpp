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
	int line,n,m;
	cin>>line>>n>>m;
	vector<int> l(n),x(m),y(m);
	rep(i,n)cin>>l[i];
	rep(i,m)cin>>x[i]>>y[i];

	vector<int> diff(n-1);
	rep(i,n-1){
		diff[i] = l[i+1] - l[i]-1;
	}
	int front=l[0]-1, back=line-l[n-1];
	sort(all(diff));
	vector<int> sum(n,0);
	rep(i,n-1)sum[i+1] = sum[i]+diff[i];

	rep(i,m){
		int k = upper_bound(all(diff),x[i]+y[i]) - diff.begin();
		int ans = n;
		int res=0;
		if(k>0)res += sum[k];
		res += (x[i]+y[i])*(n-k-1);
		ans += res;
		ans += min(front,x[i]);
		ans += min(back,y[i]);
		cout<<ans<<endl;
	}

	return 0;
}