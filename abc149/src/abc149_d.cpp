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
	ll n,k,r,s,p;
	string t;
	cin>>n>>k>>r>>s>>p>>t;

	vector<int> used(n,-1);
	ll ans=0;
	rep(pos,n){
		if(used[pos]>0)break;
		char hand = 'a';
		for (int i = pos; i < n; i+=k){
			used[i] = 1;
			if(hand==t[i]){
				hand = 'a';
			}else{
				if(t[i]=='r')ans+=p,hand='r';
				else if(t[i]=='s')ans+=r,hand='s';
				else ans+=s,hand='p';
			}
			// cout<<ans<<endl;
		}
	}

	cout<<ans<<endl;
	return 0;
}