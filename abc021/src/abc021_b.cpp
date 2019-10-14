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
bool valid(int lx,int ux,int ly,int uy,int x,int y){
	return lx<=x&&x<ux&&ly<=y&&y<uy; 
}

int main()
{
	int n,a,b,k;
	cin>>n>>a>>b>>k;
	vector<int> p(k);
	rep(i,k)cin>>p[i];
	bool is_a=false,is_b=false,loop=false;

	sort(all(p));
	rep(i,k){
		if(p[i]==a)is_a=true;
		if(p[i]==b)is_b=true;
		if(i!=0&&p[i]==p[i-1])loop=true;
	}

	if(is_a||is_b||loop)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;	
	return 0;
}