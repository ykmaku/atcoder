#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}
ll power(ll x,ll p){
	if(p==0)return 1;
	ll res=power(x*x%mod,p/2);
	if(p%2==1)res=res*x%mod;
	return res;
}

vector<int> divisor(int n)
{
	vector<int> res;

	for(int i = 1; i * i <= n; i++)
	{
		if (n % i==0)
		{
			res.push_back(i);
			if (i != n / i)
			{
				res.push_back(n / i);
			}
		}
	}

	// sort(all(res));  //O(\sprt(n)log(n))

	return res;
}

int main()
{
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	rep(i,n)cin>>a[i]>>b[i];
	vector<int> factors=divisor(a[0]), factors_b=divisor(b[0]);
	factors.insert(factors.end(), all(factors_b));

	vector<int> candidate;
	for(auto x: factors){
		bool flag=true;
		rep(i,n){
			if(a[i]%x==0 || b[i]%x==0)continue;
			flag=false;
		}
		if(flag)candidate.emplace_back(x);
	}
	cout<<*max_element(all(candidate))<<endl;

	return 0;
}