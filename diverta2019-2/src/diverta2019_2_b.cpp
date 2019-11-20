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
	vector<P> point(n);
	rep(i,n)cin>>point[i].first>>point[i].second;

	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	int ans=INF;

	rep(i,n){
		rep(j,n){
			if(i==j)continue;

			int p = point[j].first - point[i].first;
			int q = point[j].second - point[i].second;

			// vector<int> used(n,1);
			// used[i]=0,used[j]=0;
			int res=n-1;
			rep(k,n){
				if(k==i) continue;
				rep(l,n){
					int pp = point[l].first - point[k].first;
					int qq = point[l].second - point[k].second;
					if(pp==p && qq==q) res--;
				}
			}
			// res += accumulate(all(used),0);
			ans=min(ans,res);
		}
	}

	cout<<ans<<endl;

	return 0;
}