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

int len(string s,string l,string r){
	string t;
	int i=0;
	while(i<s.size()){
		if(i<s.size()-1){
			if(s.substr(i,2)==l) t+='L',i++;
			else if(s.substr(i,2)==r)t+='R',i++;
			else t+=s[i];
		}else t+=s[i];
		i++;
	}
	// cout<<t<<endl;

	return t.size();
}

int main()
{
	int n;
	string s;
	cin>>n>>s;

	int ans=s.size();
	char d[]={'A','B','X','Y'};
	rep(i,4)rep(j,4)rep(k,4)rep(l,4){
		string L;
		string R;
		L+=d[i];
		L+=d[j];
		R+=d[k];
		R+=d[l];
		ans=min(ans,len(s,L,R));
	}
	cout<<ans<<endl;
	return 0;
}