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
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	P first=P(-1,-1),second=P(-1,-1);
	rep(i,n){
		if(first.first<a[i]) first=P(a[i],i);
	}
	rep(i,n){
		if(second.first<a[i]&&i!=first.second) second=P(a[i],i);
	}
	rep(i,n) cout<<(i!=first.second?first.first:second.first)<<endl;
	return 0;
}