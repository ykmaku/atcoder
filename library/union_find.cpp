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