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
	int h,w,k;
	cin>>h>>w>>k;
	vector<vector<int>> grid(h,vector<int>(w,0));
	rep(i,h){
		string s;
		cin>>s;
		rep(j,s.size())if(s[j]=='1')grid[i][j]=1;
	}

	int ans = 1e9;
	rep(bit,(1<<h)){
		map<int, int> mp;
		int tmp=0;
		int prev = bit&1;
		// cout<<"----------"<<endl;
		// cout<<"prev = "<<prev<<endl;
		// cout<<bit<<endl;
		rep(i,h){
			// cout<<(bit>>i)<<" "<<(1&(bit>>i))<<endl;
			if((1&(bit>>i))==prev) mp[i]=tmp;
			else{
				tmp++;
				prev = 1&(bit>>i);
				mp[i] = tmp;
			}
		}
		// cout<<"tmp = "<<tmp<<endl;
		vector<int> cnt1(tmp+1,0);
		
		int res = tmp;
		rep(i,w){
			bool flg=false;
			vector<int> cnt2(tmp+1,0);
			rep(j,h){
				cnt1[mp[j]] += grid[j][i];
				cnt2[mp[j]] += grid[j][i];
			}

			rep(j,h){
				if(cnt1[mp[j]]>k) flg = true;
				if(cnt2[mp[j]]>k) res = 1e8;
			}

			if(flg){
				res += 1;
				rep(j,h)cnt1[mp[j]]=cnt2[mp[j]];
			}
		}

		ans = min(ans,res);
		// cout<<tmp<<" "<<res<<endl;
	}

	cout<<ans<<endl;

	return 0;
}