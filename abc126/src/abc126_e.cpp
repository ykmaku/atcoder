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

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

struct union_find{
  vector<int> par,r;

  union_find(int n) : par(n),r(n){init(n);}

  void init(int n){
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
	int n,m;
	cin>>n>>m;
	vector<int> x(m),y(m);
	for(int i = 0; i < m; i++){
		int z;
		cin>>x[i]>>y[i]>>z;
	}
	union_find uf(n);
	for(int i = 0; i < m; i++){
		x[i]--;
		y[i]--;
		if(!uf.same(x[i],y[i]))
			uf.unite(x[i],y[i]);
	}

	int ans=0;
	for(int i = 0; i < n; i++){
		if(uf.par[i]==i)
			ans++;
	}
	cout<<ans<<endl;

	return 0;
}