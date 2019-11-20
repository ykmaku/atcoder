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

int translate(int m,int d){
	set<int> days30 = {4,6,9,11};

	int ret=0;
	rep(i,m-1){
		if(i+1==2)ret+=29;
		else if(days30.count(i+1)>0)ret+=30;
		else ret+=31;
	}
	return ret+d-1;

}

int main()
{
	int n;
	cin>>n;
	vector<P> happy(n);
	rep(i,n){
		int m,d;
		scanf("%d/%d",&m,&d);
		// m--;d--;
		happy[i] = P(m,d);
	}

	vector<int> day(366,0);
	rep(i,366){
		if(i%7==0){
			day[i]=1;
			if(i>0)day[i-1]=1;
		}
	}

	rep(i,n){
		int target = translate(happy[i].first,happy[i].second);
		while(target<366&&day[target]>0)target++;
		if(target<366) day[target]=1;
	}

	int cnt=0;
	int ans=0;
	rep(i,366){
		if(day[i]>0)cnt++;
		else cnt=0;
		ans=max(ans,cnt);

	}
	cout<<ans<<endl;

	
	return 0;
}