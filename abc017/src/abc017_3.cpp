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
	cin>>n>>m;
	vector<tuple<int,int,ll>> iseki(n);
	rep(i,n){
		int l,r;
		ll s;
		cin>>l>>r>>s;
		l--,r--;
		tuple<int,int,ll> t=make_tuple(l,r,s);
		iseki[i]=t;
	}

	vector<ll> sum(m+1);
	rep(i,n){
		int l=get<0>(iseki[i]);
		int r=get<1>(iseki[i]);
		ll 	s=get<2>(iseki[i]);
		sum[l]+=s;
		sum[r+1]-=s;
	}
	rep(i,m) sum[i+1]+=sum[i];
	sum[m] = INF*INF;
	int mini=-1;
	ll min_sum=*min_element(all(sum));
	rep(i,m){
		if(sum[i]==min_sum){
			mini=i;
			break;
		}
	}

	ll ans=0;
	rep(i,n){
		int l=get<0>(iseki[i]);
		int r=get<1>(iseki[i]);
		ll 	s=get<2>(iseki[i]);
		if(!(l<=mini&&mini<=r))ans+=s;
	}
	cout<<ans<<endl;

	return 0;
}