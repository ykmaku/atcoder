#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>
 
using namespace std;
 
typedef long long int ll;
typedef pair<ll,int> P;
 
#define all(x) x.begin(),x.end()
 
const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;
 
int n;
vector<int> dst;
vector<vector<P> > g;

void dfs(int r){
    for(int i = 0; i < g[r].size(); i++){
        if(dst[g[r][i].second]<0){
            dst[g[r][i].second] = dst[r] + g[r][i].first;
            dfs(g[r][i].second);
        }
    }
}

int tree_diameter(){
    dst.resize(n,-1);
    dst[0]=0;
    dfs(0);
    int p=0,d=-1;
    for(int i = 0; i < n; i++){
        if(dst[i]>d){
            d = dst[i];
            p=i;
        }
    }
    for(int i = 0; i < n; i++){
        dst[i]=-1;
    }
    dst[p]=0;
    dfs(p);
    d=-1;
    for(int i = 0; i < n; i++){
        d = max(d,dst[i]);
    }
    return d;
}
 
 
int main()
{
    cin>>n;
    g.resize(n);
    for(int i = 0; i < n-1; i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back(P(w,b));
        g[b].push_back(P(w,a));
 
    }
 
    cout<<tree_diameter()<<endl;
 
    return 0;
}