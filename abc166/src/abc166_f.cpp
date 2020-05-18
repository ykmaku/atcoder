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

bool isin(string s, char c){
	rep(i,s.size()){
		if(s[i]==c)return true;
	}
	return false;
}

int main()
{
	int n;
	vector<int> x(3);
	cin>>n;
	rep(i,3)cin>>x[i];
	vector<string> s(n);
	rep(i,n)cin>>s[i];

	vector<char> ans;
	rep(i,n){

		if(x[s[i][0]-'A']==0 && x[s[i][1]-'A']==0){
			cout<<"No"<<endl;
			return 0;
		}

		if(x[s[i][0]-'A'] < x[s[i][1]-'A']){
			x[s[i][0]-'A']++;
			x[s[i][1]-'A']--;
			ans.push_back(s[i][0]);
		}else if(x[s[i][0]-'A'] > x[s[i][1]-'A']){
			x[s[i][0]-'A']--;
			x[s[i][1]-'A']++;
			ans.push_back(s[i][1]);
		}else{
			if(i==n-1)ans.push_back(s[i][0]);
			else if(s[i+1]==s[i]){
				x[s[i][0]-'A']--;
				x[s[i][1]-'A']++;
				ans.push_back(s[i][1]);
			}else if(isin(s[i+1],s[i][0])){
				x[s[i][0]-'A']++;
				x[s[i][1]-'A']--;
				ans.push_back(s[i][0]);
			}else{
				x[s[i][0]-'A']--;
				x[s[i][1]-'A']++;
				ans.push_back(s[i][1]);
			}
		}
	}

	cout<<"Yes"<<endl;
	rep(i,n)cout<<ans[i]<<endl;
	return 0;
}
