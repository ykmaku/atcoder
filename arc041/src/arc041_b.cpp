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
	vector<vector<int>> b(n,vector<int>(m,0)),a(n,vector<int>(m,0));
	rep(i,n){
		string s;
		cin>>s;
		rep(j,m){
			b[i][j]=s[j]-'0';
		}
	}

	repi(i,1,n-1){
		repi(j,1,m-1){
			int min_value=1000;
			rep(k,4)min_value=min(min_value,b[i+dx[k]][j+dy[k]]);

			if(min_value>0){
				rep(k,4)b[i+dx[k]][j+dy[k]]-=min_value;
				a[i][j]+=min_value;
			}
		}
	}

	rep(i,n){
		rep(j,m)cout<<a[i][j];
		cout<<endl;
	}

	return 0;
}