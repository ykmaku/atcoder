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

int main()
{
	vector<char> b(10);
	rep(i,10)cin>>b[i];
	map<char,char> digit,rev;
	rep(i,10){
		digit[b[i]] = '0'+i;
		rev['0'+i] = b[i];
	}
	int n;
	cin>>n;
	vector<string> s(n);
	rep(i,n)cin>>s[i];
	rep(i,n){
		rep(j,s[i].size()){
			s[i][j] = digit[s[i][j]];
		}
	}
	sort(all(s),[&](string s,string t){
		return stoi(s)<stoi(t);
	});
	rep(i,n){
		rep(j,s[i].size()){
			s[i][j] = rev[s[i][j]];
		}
	}
	rep(i,n)cout<<s[i]<<endl;
	return 0;
}