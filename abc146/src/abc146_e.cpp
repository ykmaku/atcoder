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
	int n;
	ll k;
	cin>>n>>k;
	vector<ll> a(n,0);
	rep(i,n)cin>>a[i];

	vector<ll> sum(n+1,0);
	rep(i,n)sum[i+1] = sum[i]+a[i];

	vector<ll> target(n+1);
	rep(i,n+1){
		target[i] = (sum[i]-i+k)%k;
	}

	ll ans=0;
	map<ll,ll> mp;
	mp[0] = 1;
	int cnt=1;
	repi(i,1,n+1){
		if(cnt==k){
			mp[target[i-k]]=max(0LL,mp[target[i-k]]-1);
			ans += mp[target[i]];
			mp[target[i]]+=1;
		}else{
			ans += mp[target[i]];
			mp[target[i]]+=1;
			cnt++;
		}
	}

	cout<<ans<<endl;

	return 0;
}