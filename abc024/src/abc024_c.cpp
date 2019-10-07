#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

bool finish(int l,int r,int s,int t){
	return (l<=s&&s<=r&&l<=t&&t<=r);
}

int main()
{
	int n,d,k;
	cin>>n>>d>>k;
	vector<P> x(d);
	rep(i,d)cin>>x[i].first>>x[i].second;
	vector<P> pos(k);
	rep(i,k)cin>>pos[i].first>>pos[i].second;

	vector<int> ans(k,-1);
	rep(i,d){
		rep(j,k){
			if(ans[j]>=0)continue;
			if(finish(x[i].first,x[i].second,pos[j].first,pos[j].second))ans[j]=i;
			else if(x[i].first<=pos[j].first&&pos[j].first<=x[i].second){
				if(pos[j].first<pos[j].second)pos[j].first=x[i].second;
				else pos[j].first=x[i].first;
			}
		}
	}

	rep(i,k)cout<<ans[i]+1<<endl;

	return 0;
}