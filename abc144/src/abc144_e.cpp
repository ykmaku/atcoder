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

bool hantei(vector<ll> &a,vector<ll> &f,ll k,ll score){
	ll n = a.size();
	ll cnt=0;
	rep(i,n){
		cnt += max(0LL,a[i]-(score)/f[i]);
	}

	return cnt<=k;
}

int main()
{
	ll n,k;
	cin>>n>>k;
	vector<ll> a(n),f(n);
	rep(i,n)cin>>a[i];
	rep(i,n)cin>>f[i];

	if(accumulate(all(a),0LL)<=k){
		cout<<0<<endl;
		return 0;
	}

	sort(all(a));
	sort(all(f));
	reverse(all(f));

	ll low=0,high=1e12;

	while(low+1<high){
		ll mid=(low+high)/2;
		if(hantei(a,f,k,mid)){
			high=mid;
		}else{
			low=mid;
		}
	}

	cout<<(hantei(a,f,k,low)?low:high)<<endl;

	return 0;
}