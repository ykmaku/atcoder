#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> tp;

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


struct union_find{
	int n;
  vector<int> par,rank,size;

  // 頂点xの根を見たいときはuf.find(x)を使う
  union_find(int _n) : n(_n),par(_n),rank(_n),size(_n){init(n);}

  void init(int n){
    rep(i,n) par[i]=i,rank[i]=i,size[i]=1;
  }

  int GetRoot(int x){
    if(par[x] == x) return x;
    else return GetRoot(par[x]);
  }

  int GetSize(int x){
    return size[GetRoot(x)];
  }

  ll getNumOfComponents(){
    ll num=0;
    rep(i,n)if(GetRoot(i)==i)num++;
    return num;
  }

  void Unite(int x,int y){
    x = GetRoot(x);
    y = GetRoot(y);
    if(x == y) return;
    if(rank[x] < rank[y]){
      par[x] = y;
      size[y]+=size[x];
    }else{
      par[y] = x;
      size[x]+=size[y];
      if(rank[x] == rank[y]) rank[x]++;
    }
  }

  bool Same(int x,int y){
    return GetRoot(x) == GetRoot(y);
  }
};

int main()
{
	ll n,m,q;
	cin>>n>>m>>q;
	vector<tp> query(q);
	rep(i,q){
		int a,b,c;
		cin>>a>>b>>c;
		query[i] = tp(c,a,b);
	}

	bool flag=false;
	union_find uf(n);
	rep(i,q){
		if(get<0>(query[i])==1){
			flag=true;
			continue;
		}
		int a=get<1>(query[i]), b = get<2>(query[i]);
		if(!uf.Same(a,b))uf.Unite(a,b);
	}

	rep(i,q){
		if(get<0>(query[i])==0) continue;
		int a=get<1>(query[i]), b = get<2>(query[i]);
		if(uf.Same(a,b)){
			cout<<"No"<<endl;
			return 0;
		}
	}

	ll comp = uf.getNumOfComponents();

	ll large = comp*(comp-1)/2 + (n-comp);
	ll small = (flag?n:n-1);

	if(small<=m&&m<=large)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}