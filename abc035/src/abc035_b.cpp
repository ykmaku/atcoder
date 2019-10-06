#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	string s;
	int t;
	cin>>s>>t;
	ll lr=0,ud=0,q=0;
	rep(i,s.size()){
		if(s[i]=='L')lr--;
		if(s[i]=='R')lr++;
		if(s[i]=='U')ud++;
		if(s[i]=='D')ud--;
		if(s[i]=='?')q++;
	}

	ll dist=abs(lr)+abs(ud);
	if(t==1){
		cout<<dist+q<<endl;
	}else{
		if(q>dist) q-=dist,cout<<q%2<<endl;
		else cout<<dist-q<<endl;

	}
	return 0;
}