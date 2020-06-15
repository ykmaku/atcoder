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

ll f2(int n, int p, string s){
	ll ans=0;
	reverse(all(s));
	rep(i,n){
		if((s[i]-'0')%p==0) ans += (n-i);
	}
	return ans;
}

ll f5(int n, int p, string s){
	ll ans=0;
	reverse(all(s));
	rep(i,n){
		if((s[i]-'0')%p==0) ans += (n-i);
	}
	return ans;
}

ll fp(int n, int p, string s){
	ll ans=0;
	reverse(all(s));
	vector<int> res(n,0);
	rep(i,n){
		res[i] = (s[i]-'0') % p;
	}
	ll ten=10;
	repi(i,1,n){
		res[i] = (res[i]*ten + res[i-1]) % p;
		ten = ten*10 % p;
	}
	map<int, ll>mp;
	rep(i,n){
		mp[res[i]] += 1;
	}


	// mp[0]++;
	rep(i,p) ans += mp[i] * (mp[i]-1)/2;
	ans += mp[0];
	return ans;
}

int main()
{
	int n,p;
	string s;
	cin>>n>>p>>s;
	ll ans;
	if(p==2) ans = f2(n,p,s);
	else if(p==5) ans = f5(n,p,s);
	else ans = fp(n,p,s);
	cout<<ans<<endl;
	return 0;
}