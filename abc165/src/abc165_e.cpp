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
	int n,m;
	cin>>n>>m;
	int cnt=0;
	if(n%2==0){
		rep(i,m){
			if(cnt==m)break;
			cnt++;
			cout<<i+1<<" "<<n/2-i<<endl;
			if(cnt==m)break;
			cnt++;
			cout<<n/2+(i+1)<<" "<<n-i<<endl;
		}
	}else{
		rep(i,m){
			if(cnt==m)break;
			cnt++;
			cout<<i+1<<" "<<(n+1)/2-i<<endl;
			if(cnt==m)break;
			cnt++;
			cout<<(n+1)/2+(i+1)<<" "<<n-i<<endl;
		}
	}
	return 0;
}