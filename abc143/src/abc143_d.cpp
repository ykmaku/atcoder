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
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}

int main()
{
	int n;
	cin>>n;
	vector<int> l(n);
	rep(i,n)cin>>l[i];
	sort(all(l));

	ll ans=0;
	for (int i = n-1; i >= 0; i--){
		for (int j = i-1; j >= 0; j--){
			int e = l[i]-l[j];
			int pos=upper_bound(all(l),e)-l.begin();

			ans += max(j-pos,0);
		}
	}
	cout<<ans<<endl;

	return 0;
}