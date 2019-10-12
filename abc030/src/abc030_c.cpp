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

int main()
{
	int n,m;
	ll x,y;
	cin>>n>>m>>x>>y;
	vector<ll> a(n),b(m);
	rep(i,n)cin>>a[i];
	rep(i,m)cin>>b[i];

	ll time=0;
	int pos=0;
	int ans=0;
	while(1){
		if(pos==0){
			auto it = lower_bound(all(a),time);
			if(it==a.end())break;
			int plane=it-a.begin();
			time=a[plane]+x;
			pos=1;
		}else{
			auto it = lower_bound(all(b),time);
			if(it==b.end())break;
			int plane=it-b.begin();
			time=b[plane]+y;
			pos=0;
			ans++;
		}
	}

	cout<<ans<<endl;

	return 0;
}