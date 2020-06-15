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
	string s;
	int q;
	cin>>s>>q;
	deque<char> que;
	for(auto c: s)que.push_back(c);

	bool rev=false;
	rep(i,q){
		int t;
		cin>>t;
		if(t==1){
			if(rev)rev=false;
			else rev=true;
			continue;
		}
		int f;
		char c;
		cin>>f>>c;
		if(rev){
			if(f==1)que.push_back(c);
			else que.push_front(c);
		}else{
			if(f==1)que.push_front(c);
			else que.push_back(c);
		}
	}
	string ans;
	for(auto x:que)ans+=x;
	if(rev) reverse(all(ans));
	cout<<ans<<endl;
	return 0;
}