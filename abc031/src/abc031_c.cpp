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

	int ans=-INF;
	rep(taka,n){
		int sum_aoki=-INF,sum_taka=-INF;
		rep(aoki,n){
			if(aoki==taka)continue;
			int res_aoki=0,res_taka=0;
			int cnt=0;
			repi(i,min(taka,aoki),max(taka,aoki)+1){
				if(cnt%2==0)res_taka+=a[i];
				else res_aoki+=a[i];
				cnt++;
			}
			if(sum_aoki<res_aoki){
				sum_aoki=res_aoki;
				sum_taka=res_taka;
			}
		}
		ans=max(ans,sum_taka);
	}
	cout<<ans<<endl;

	return 0;
}