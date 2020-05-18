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

typedef struct point{
	int a,b,c,d;
	point(int aa,int bb,int cc, int dd){
		a=aa;b=bb;c=cc;d=dd;
	}
} point;

int n,m,q;
vector<point> p;
int best = 0;

void calc(vector<int> ls){
	int res=0;
	for(auto pp: p){
		if(ls[pp.b] - ls[pp.a] == pp.c)res += pp.d;
	}
	best = max(best, res);
}

void dfs(vector<int> ls, int pos){
	if(pos==n){
		calc(ls);
	}else{
		int x = (pos==0?1:ls[pos-1]);
		repi(i, x, m+1){
			ls[pos] = i;
			dfs(ls, pos+1);
		}
	}
}


int main()
{
	cin>>n>>m>>q;
	rep(i,q){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--;b--;
		p.push_back(point(a,b,c,d));
	}

	vector<int> ls(n,0);

	dfs(ls, 0);

	cout<<best<<endl;
	return 0;
}