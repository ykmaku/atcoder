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

bool is_include(string s,char c){
	rep(i,s.size())if(s[i]==c)return true;

	return false;
}

bool same(string s){
	repi(i,1,s.size())if(s[i]!=s[0])return false;
	return true;
}

int main()
{
	string s;
	cin>>s;
	int ans=INF;
	rep(i,26){
		bool flag=false;
		char target='a'+i;
		string t=s;
		int cnt=0;
		if(!is_include(t,target))continue;

		while(1){
			bool used=false;
			rep(j,t.size()-1)if(t[j+1]==target&&t[j]!=t[j+1])t[j]=target,used=true;
			int diff=0;
			rep(j,t.size())if(t[j]!=target)diff++;

			if(used)cnt++;
			if(!used){
				ans=min(ans,max(diff,cnt));
				break;
			}
			if(diff<=cnt){
				ans=min(ans,cnt);
				break;
			}
			if(target=='r')cout<<t<<endl;
		}
			cout<<t<<" "<<cnt<<endl;
	}
	cout<<ans<<endl;
	return 0;
}