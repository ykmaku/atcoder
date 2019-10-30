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
	int x,y;
	string w;
	cin>>x>>y>>w;
	x--,y--;
	vector<string> s(9);
	rep(i,9)cin>>s[i];
	vector<vector<int>> c(9,vector<int>(9));
	rep(i,9)rep(j,9)c[i][j]=s[i][j]-'0';

	int cnt=4;
	vector<int> ans;
	while(cnt--){
		ans.push_back(c[y][x]);
		
		if(w=="R"){
			if(x==8)x=7,w="L";
			else x++;
		}else if(w=="L"){
			if(x==0)x=1,w="R";
			else x--;
		}else if(w=="D"){
			if(y==8)y=7,w="U";
			else y++;
		}else if(w=="U"){
			if(y==0)y=1,w="D";
			else y--;
		}else if(w=="RU"){
			string rl="R",ud="U";
			if(x==8)x=7,rl="L";
			else x++;
			if(y==0)y=1,ud="D";
			else y--;
			w=rl+ud;
		}else if(w=="RD"){
			string rl="R",ud="D";
			if(x==8)x=7,rl="L";
			else x++;
			if(y==8)y=7,ud="U";
			else y++;
			w=rl+ud;
		}else if(w=="LU"){
			string rl="L",ud="U";
			if(x==0)x=1,rl="R";
			else x--;
			if(y==0)y=1,ud="D";
			else y--;
			w=rl+ud;
		}else if(w=="LD"){
			string rl="L",ud="D";
			if(x==0)x=1,rl="R";
			else x--;
			if(y==8)y=7,ud="U";
			else y++;
			w=rl+ud;
		}
	}
	rep(i,4)cout<<ans[i];
	cout<<endl;
	return 0;
}