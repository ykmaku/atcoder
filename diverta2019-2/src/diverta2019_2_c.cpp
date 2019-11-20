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

	sort(all(a));

	if(n==2){
		cout<<a[1]-a[0]<<endl;
		cout<<a[1]<<" "<<a[0]<<endl;
		return 0;
	}

	vector<P> ans;
	deque<int> b;
	if(a[0]>=0){
		ans.push_back(P(a[0],a[n-1]));
		a[0]-=a[n-1];
		rep(i,n-1)b.push_back(a[i]);
	}else if(a[n-1]<=0){
		ans.push_back(P(a[n-1],a[0]));
		a[n-1] -= a[0];
		repi(i,1,n)b.push_back(a[i]);
	}else{
		rep(i,n)b.push_back(a[i]);
	}

	int min_ = b.front();b.pop_front();
	int max_ = b.back();b.pop_back();

	for(auto x:b){
		if(x>0){
			ans.push_back(P(min_,x));
			min_ -= x;
		}else{
			ans.push_back(P(max_,x));
			max_ -= x;
		}
	}
	ans.push_back(P(max_,min_));
	cout<<max_ - min_<<endl;
	for(auto x:ans){
		cout<<x.first<<" "<<x.second<<endl;
	}


	return 0;
}