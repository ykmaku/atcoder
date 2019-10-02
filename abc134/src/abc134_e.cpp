#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const int INF = 1e9+10;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n)cin>>a[i],a[i];
	reverse(all(a));

	vector<int> dp(n,INF);
	rep(i,n){
		*upper_bound(all(dp),a[i])=a[i];
	}

	cout<<lower_bound(all(dp),INF)-dp.begin()<<endl;

	return 0;
}