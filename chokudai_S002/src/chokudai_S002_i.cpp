#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
// typedef pair<double, double> P;
typedef tuple<ll,ll,int> P;

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

ll calc(P p1, P p2){
	return (get<0>(p2)+get<1>(p1)-1) / get<1>(p1) < (get<0>(p1)+get<1>(p2)-1) / get<1>(p2);
}

int main()
{
	int n;
	cin>>n;
	vector<P> v(n);
	rep(i,n){
		ll a,b;
		cin>>a>>b;
		v[i] = P(a,b,i+1);
	}

	P winner = v[0];
	repi(i,1,n){
		P ch = v[i];
		if(!calc(winner, ch)) winner = ch;
	}

	rep(i,n){
		if(get<2>(winner)==i+1)continue;
		if(!calc(winner, v[i])){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<get<2>(winner)<<endl;

	return 0;
}