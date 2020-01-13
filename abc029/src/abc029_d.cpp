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
	ll res=power(x*x,p/2);
	if(p%2==1)res=res*x;
	return res;
}

ll func(int k){
	if(k<=0)return 0;
	ll ret = 0;
	rep(i,k){
		if(i==0)ret=1;
		else ret = power(10,i) + ret*9;
	}
	return ret;
}

ll solve(ll x){
	int ans=0;
	rep(i,x+1){
		int res=i;
		while(res>0){
			if(res%10==1)ans++;
			res/=10;
		}
	}
	return ans;
}


int main()
{
	ll n;
	cin>>n;

	ll ans=0;
	ll res = n;
	while(res>0){
		ans += (res/10) + (res%10>0?1:0);
		res/=10;
	}
	cout<<ans<<endl;
	cout<<"correct = "<<solve(n)<<endl;
	return 0;
}