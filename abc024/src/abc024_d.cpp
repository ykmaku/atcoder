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

ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}

int main()
{
	ll A,B,C;
	cin>>A>>B>>C;
	ll x=((A*B)%mod+(A*C)%mod-(B*C)%mod+10*mod)%mod;
	
	ll r = ((B*C)%mod-(A*C)%mod+mod)%mod*power(x,mod-2);
	r%=mod;
	ll c = ((B*C)%mod-(A*B)%mod+mod)%mod*power(x,mod-2);
	c%=mod;
	cout<<r<<" "<<c<<endl;
	return 0;
}