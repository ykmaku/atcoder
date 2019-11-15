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
	int n,x;
	cin>>n>>x;
	vector<int> w(n);
	rep(i,n)cin>>w[i];
	vector<int> a1(n/2),a2(n-n/2);
	copy(w.begin(),w.begin()+n/2,a1.begin());
	copy(w.begin()+n/2,w.end(),a2.begin());

	map<int,int> half1,half2;
	int m1=a1.size(),m2=a2.size();
	rep(bit,(1<<m1)){
		int res=0;
		rep(j,m1){
			if(bit&(1<<j)) res+=a1[j];
		}
		half1[res]+=1;
	}
	rep(bit,(1<<m2)){
		int res=0;
		rep(j,m2){
			if(bit&(1<<j)) res+=a2[j];
		}
		half2[res]+=1;
	}

	int ans=0;
	for(auto p:half1){
		if(half2.find(x-p.first)!=half2.end())ans+=half2[x-p.first]*p.second;
	}

	cout<<ans<<endl;

	return 0;
}