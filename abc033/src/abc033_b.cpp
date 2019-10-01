#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i,(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	int n;
	cin>>n;
	vector<pair<string,int>> city(n);
	int sum=0;
	rep(i,n){cin>>city[i].first>>city[i].second;sum+=city[i].second;}
	string ans="atcoder";
	rep(i,n)if(city[i].second>sum/2)ans=city[i].first;
	cout<<ans<<endl;
	return 0;
}