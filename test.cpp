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
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m);
	rep(i,n)cin>>a[i];
	rep(i,m)cin>>b[i];
	vector<P> check(2*1e6+1,P(-1,-1));

	rep(i,n){
		rep(j,m){
			P now=check[a[i]+b[j]];
			if(now.first>=0){
				cout<<now.first<< " "<<now.second<<" "<<i<<" "<<j<<endl;
				return 0;
			}
			check[a[i]+b[j]]=P(i,j);
		}
	}
	cout<<-1<<endl;
	return 0;
}