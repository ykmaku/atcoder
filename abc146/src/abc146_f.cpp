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

typedef struct segtree{
	int n;
	vector<int> a;
	segtree(){};
	segtree(int n){init(n);};

	void init(int n_){
		n = 1;
		while(n<n_)n*=2;
		a.resize(2*n-1,INT_MAX);
	}

	void update(int pos,int x){
		pos += n-1;
		a[pos]=x;
		while(pos>0){
			pos = (pos-1)/2;
			a[pos] = min(a[2*pos+1], a[2*pos+2]);
		}
	}

	int findMinValue(int ll,int rr){
		int vl=INT_MAX,vr=INT_MAX;
		for (int l=ll+n, r=rr+n ; l<r ; l=(l>>1),r=(r>>1)){
			if(l&1) vl=min(vl,a[l-1]),l++;
			if(r&1) r--,vr=min(vr,a[r-1]);
		}
		return min(vl,vr);
	}

}segtree;

int main()
{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;

	vector<int> dist(n+1,1e9);
	dist[n]=0;

	segtree seg(n+1);
	seg.update(n,0);

	repr(i,n-1,0){
		if(s[i]=='1')continue;
		int val;
		if(n-i<=m) val = seg.findMinValue(i,n+1);
		else val = seg.findMinValue(i,i+m+1);
		// cout<<val<<endl;
		if(val==INT_MAX){
			cout<<-1<<endl;
			return 0;
		}
		dist[i]=val+1;
		seg.update(i,dist[i]);
	}

	vector<int> ans;
	int prev=0;

	repi(i,1,n+1){
		if(dist[i]<dist[prev]){
			ans.push_back(i-prev);
			prev=i;
		}
	}

	for(auto x:ans)cout<<x<<" ";
	cout<<endl;

	return 0;
}