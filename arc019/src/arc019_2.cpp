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
	string s;
	cin>>s;
	if(s.size()==1)cout<<0<<endl;
	else{
		int n = s.size();
		int left=0,right=n-1;
		vector<int> match((n+1)/2,0);
		while(left<=right){
			if(s[left]==s[right])match[left]=1;
			left++,right--;
		}
		int sum = accumulate(all(match),0);
		int ans=0;
		rep(i,(n+1)/2){
			int res = sum;
			res -= match[i];
			if(res+1==(n+1)/2){
				if(n!=1){
					if(i==n-1-i)ans+=0;
					else if(match[i]>0)ans+=50;
					else ans+=48;
				}
			}else{
				ans += 50;
				if(i==n-1-i)ans-=25;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}