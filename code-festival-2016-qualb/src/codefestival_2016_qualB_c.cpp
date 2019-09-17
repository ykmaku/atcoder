#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;

typedef long long int ll;
typedef pair<ll,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct union_find{
  vector<int> par,r;
  int cmp;

  union_find(int n) : par(n),r(n){init(n);}

  void init(int n){
	cmp=n;
    for(int i = 0; i < n; i++) par[i] = i;
    for(int i = 0; i < n; i++) r[i] = 0;
  }

  int find(int x){
    if(par[x] == x) return x;
    else return find(par[x]);
  }

  void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
	cmp--;
    if(r[x] < r[y]){
      par[x] = y;
    }else{
      par[y] = x;
      if(r[x] == r[y]) r[x]++;
    }
  }

  bool same(int x,int y){
    return find(x) == find(y);
  }
};

int main()
{
	ll w,h;
	cin>>w>>h;
	vector<P> p(w+h);
	for (int i = 0; i < w; i++){
		cin>>p[i].first;
		p[i].second = i;
	}
	for (int i = w; i < w+h; i++){
		cin>>p[i].first;
		p[i].second = i;
	}
	sort(all(p));

	union_find uf_x(w+1),uf_y(h+1);


	ll ans=0;
	rep(i,w+h){
		int pos = p[i].second;
		if(pos<w){
			// cout<< pos<<" "<<pos+1 <<" "<< uf_y.cmp<<" " <<(ll)uf_y.cmp*p[i].first<<endl;
			ans += (ll)uf_y.cmp*p[i].first;
			// cout<<uf_x.find(pos)<<" "<<uf_x.find(pos+1)<<endl;
			if(!uf_x.same(pos,pos+1)){
				uf_x.unite(pos,pos+1);
			}
		}else{
			pos -= w;
			// cout<<uf_x.cmp<<" " <<(ll)uf_x.cmp*p[i].first<<endl;
			ans += (ll)uf_x.cmp*p[i].first;
			if(!uf_y.same(pos,pos+1)) uf_y.unite(pos,pos+1);
		}
	}


	cout<<ans<<endl;

	return 0;
}