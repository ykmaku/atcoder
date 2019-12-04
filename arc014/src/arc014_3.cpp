#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<string,int> P;

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

string transform(string s){
	string t;
	int n = s.size();
	int i=0;
	while(i<n){
		if(i<n-1&&s[i]==s[i+1])i++;
		else{
			t += s[i];
		}
		i++;
	}
	return t;
}

int main()
{
	int n;
	string s;
	cin>>n>>s;

	map<char,int> cnt;
	cnt.emplace('R',0);
	cnt.emplace('G',0);
	cnt.emplace('B',0);

	rep(i,n)cnt[s[i]]++;

	int ans=0;
	for(auto x:cnt)if(x.second%2!=0)ans++;
	cout<<ans<<endl;

	return 0;
}