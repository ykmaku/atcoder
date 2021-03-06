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
	int n;
	cin>>n;
	vector<int> h(n);
	rep(i,n)cin>>h[i];

	int left=0,right=0;
	int ans=0;
	int parity=1;
	while(right<n){
		if(right+1==n){
			ans=max(ans,right-left+1);
			break;
		}
		if(h[right]<h[right+1]&&parity>0)right++;
		else if(h[right]>h[right+1]&&parity>0)right++,parity*=-1;
		else if(h[right]>h[right+1]&&parity<0)right++;
		else if((h[right]<h[right+1]&&parity<0)){
			ans=max(ans,right-left+1);
			left=right;
			parity*=-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}