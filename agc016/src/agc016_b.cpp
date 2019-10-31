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
	vector<int> a(n);
	rep(i,n)cin>>a[i];

	int max_=*max_element(all(a)),min_=*min_element(all(a));

	bool flag=true;
	if(max_-min_>=2){
		flag=false;
	}else if(max_-min_==1){
		int max_count=0;
		rep(i,n)if(a[i]==max_)max_count++;
		int min_count=n-max_count;

		if(!(min_count<max_&&max_count>=2*(max_-min_count))) flag=false;
	}else if(max_==min_){
		if(!(max_==n-1||n>=2*max_))flag=false;
	}
	cout<<(flag?"Yes":"No")<<endl;
	return 0;
}