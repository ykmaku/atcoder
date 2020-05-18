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

ll calc(ll x, vector<ll> v, ll l){
	int low=-1,high=v.size();
	while(low<high){
		int mid=(low+high)/2;
		if(x*mid<l)low=mid;
		else high=mid;
	}
	return low+1;
}

int main()
{
	ll n,k;
	cin>>n>>k;
	vector<ll> a(n);
	rep(i,n)cin>>a[i];

	sort(all(a));

	vector<ll> minus, zero, plus;
	rep(i,n){
		if(a[i]<0)minus.push_back(a[i]);
		else if(a[i]==0)zero.push_back(a[i]);
		else plus.push_back(a[i]);
	}

	ll ms=minus.size(), ps=plus.size(), zs=zero.size();

	ll total_minus = ms*ps;
	ll total_zero = (ms+ps)*zs + zs*(zs-1)/2;


	if(total_minus<k&&k<=total_minus+total_zero){
		cout<<0<<endl;
		return 0;
	}
	if(k<=total_minus){
		ll low=-1e18-1,high=-1;
		// sort(all(plus));
		reverse(all(plus));
		while(low+1<high){
			ll L=(low+high)/2;
			ll cnt=0;
			for(auto x:minus){
				ll left=-1,right=plus.size();
				while(left+1<right){
					ll mid=(left+right)/2;
					if(x*plus[mid]<=L)left=mid;
					else right=mid;
				}
				cnt += left+1;
			}
			// reverse(all(plus));
			if(cnt<k)low=L;
			else high=L;
		}
		cout<<low+1<<endl;
	}else{
		k -= total_minus+total_zero;
		ll low=-1,high=1e18;

		rep(i,minus.size())minus[i]*=-1;
		sort(all(minus));
		sort(all(plus));
		while(low+1<high){
			ll L=(low+high)/2;
			ll cnt=0;
			rep(i,plus.size()){
				ll left = upper_bound(all(plus), L/plus[i]) - plus.begin();
				cnt += left;
				if(i<left)cnt--;
			}
			rep(i,minus.size()){
				ll left = upper_bound(all(minus), L/minus[i]) - minus.begin();
				cnt += left;
				if(i<left) cnt--;
			}
			cnt /= 2;
			if(cnt<k)low=L;
			else high=L;
		}
		cout<<low+1<<endl;
	}

	return 0;
}