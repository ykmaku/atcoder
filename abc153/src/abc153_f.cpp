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
	ll n,d,a;
	cin>>n>>d>>a;
	vector<P> p(n);
	rep(i,n)cin>>p[i].first>>p[i].second;

	sort(all(p));

	queue<P> que;
	ll sum=0,ans=0;

	rep(i,n){
		while(!que.empty()&&que.front().first<p[i].first-2*d){
			P tmp=que.front();que.pop();
			sum -= tmp.second;
		}
		p[i].second-=sum;
		if(p[i].second<=0)continue;
		ll cnt=(p[i].second+(a-1))/a;
		ans+=cnt;
		sum+=cnt*a;
		que.push(P(p[i].first, cnt*a));
	}

	cout<<ans<<endl;

	return 0;
}