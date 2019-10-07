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
	int n,t;
	cin>>n>>t;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	int ans=0;
	int from=0,to=0;
	rep(i,n){
		if(from<=a[i]&&a[i]<=to){
			to=a[i]+t;
		}else{
			ans+=to-from;
			from=a[i];
			to=a[i]+t;
		}
	}
	ans+=to-from;
	cout<<ans<<endl;
	return 0;
}