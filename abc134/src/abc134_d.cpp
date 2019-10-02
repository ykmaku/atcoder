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
	vector<int> a(n+1);
	repi(i,1,n+1)cin>>a[i];

	vector<int> b(n+1,0);
	for (int i = n; i >=1; i--){
		int cnt=0;
		for (int j = i+i; j <= n; j+=i){
			cnt+=b[j];
		}
		if(cnt%2==0){
			if(a[i]==1) b[i]=1;
		}else{
			if(a[i]==0) b[i]=1;
		}
	}
	cout<<accumulate(all(b),0)<<endl;
	repi(i,1,n+1)if(b[i]>0)cout<<i<<endl;
	return 0;
}