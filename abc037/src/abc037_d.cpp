#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> t;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}

int main()
{
	int h,w;
	cin>>h>>w;
	vector<vector<int>> a(h,vector<int>(w)),cnt(h,vector<int>(w,0));
	rep(i,h)rep(j,w)cin>>a[i][j];

	vector<t> v;
	rep(i,h)rep(j,w)v.push_back(make_tuple(a[i][j],i,j));

	sort(all(v));

	for(auto p:v){
		int i=get<1>(p),j=get<2>(p);

		cnt[i][j]++;
		rep(k,4){
			int ni=i+dy[k],nj= j+dx[k];
			if(valid(0,h,0,w,ni,nj) && a[ni][nj]>a[i][j]){
				cnt[ni][nj]+=cnt[i][j];
				cnt[ni][nj]%=mod;
			}
		}
	}

	ll ans=0;
	rep(i,h)rep(j,w)ans+=cnt[i][j],ans%=mod;

	cout<<ans<<endl;

	return 0;
}