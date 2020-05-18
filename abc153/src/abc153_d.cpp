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

int main()
{
	ll h;
	cin>>h;
	ll cnt=0,tmp=1;
	while(tmp*2<=h){
		tmp*=2;
		cnt++;
	}
	// cout<<tmp<<endl;
	// cout<<cnt<<endl;

	ll ans=0;
	while(cnt>=0){
		ans += power(2LL,cnt);
		cnt--;
		// cout<<power(2LL,cnt)<<endl;
	}
	cout<<ans<<endl;
	return 0;
}