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
	ll t[2],a[2],b[2];
	rep(i,2)cin>>t[i];
	rep(i,2)cin>>a[i];
	rep(i,2)cin>>b[i];


	ll x = (a[0]-b[0])*t[0];
	ll y = (a[1]-b[1])*t[1];

		// cout<<x<<" "<<y<<endl;
	if(x>0)x*=-1,y*=-1;
	if(x+y<0){
		cout<<0<<endl;
	}else if(x+y==0){
		cout<<"infinity"<<endl;
	}else{
		cout<<(-x)/(x+y)*2+(-x%(x+y)==0?0:1)<<endl;
	}

	return 0;
}