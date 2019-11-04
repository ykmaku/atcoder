#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<char,int> P;

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

ll cnt(string t,ll k){
	ll ret=0;
	int n=t.size();
	repi(i,1,n)if(t[i]==t[i-1])t[i]='A',ret+=k;
	return ret;
}

int main()
{
	string s;
	ll k;
	cin>>s>>k;
	ll ans=0;
	ll n=s.size();
	rep(i,n){
		if(s[i]!=s[0])break;
		if(i==n-1){
			cout<<n*k/2<<endl;
			return 0;
		}
	}
	vector<P> count;
	char c=s[0];
	int cnt=0;
	rep(i,n){
		if(s[i]==c)cnt++;
		else{
			count.emplace_back(P(c,cnt));
			cnt=1;
			c=s[i];
		}
		if(i==n-1)count.emplace_back(P(c,cnt));
	}
	if(s[0]==s[n-1]){
		for(auto x:count)ans+=x.second/2;
		ans*=k;
		int a=count[0].second, b=count[count.size()-1].second;
		ans-=(k-1)*(a/2+b/2-(a+b)/2);
	}else{
		for(auto x:count)ans+=x.second/2;
		ans*=k;
	}

	cout<<ans<<endl;

	return 0;
}