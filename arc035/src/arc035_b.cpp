#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(ll i=0;i<(n);++i)
#define repi(i,a,b) for(ll i=ll(a);i<(b);i++)
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
	ll n;
	cin>>n;
	vector<ll> t(n);
	rep(i,n)cin>>t[i];
	sort(all(t));
	vector<ll> sum(n+1,0LL);
	rep(i,n)sum[i+1]=sum[i]+t[i],sum[i+1]%=mod;

	vector<ll> memo(n+1,1LL);
	repi(i,1LL,n+1){
		memo[i] = memo[i-1]*i;
		memo[i] %= mod;
	}

	ll same=0,now=0;
	ll ans=0,cnt=1;
	rep(i,n){
		ans += sum[i+1]%mod;
		// ans %= mod;
		if(t[i]==now){
			same++;
			if(i==n-1){
				cnt *= memo[same];
				cnt %= mod;
			}
		}else if(t[i]!=now){
			if(same==0)same=1,now=t[i];
			else{
				cnt *= memo[same];
				cnt %= mod;
				same=1LL;
				now=t[i];
			}
		}
	}

	cout<<ans<<endl;
	cout<<cnt<<endl;


	return 0;
}