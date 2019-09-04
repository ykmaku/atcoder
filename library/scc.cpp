//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C 2019/9/5

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
typedef pair<int,int> P;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) x.begin(),x.end()
 
const ll mod = 1e9+7;
const ll INF = 1e9;
 
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
 
vector<vector<int>>g,rg;
vector<int> used,order,cmp;
 
void dfs(int x){
    used[x] = true;
    for(auto p:g[x]){
        if(!used[p]) dfs(p);
    }
    order.push_back(x);
}
 
void rdfs(int x,int cnt){
    used[x] = true;
    for(auto p:rg[x]){
        if(!used[p]) rdfs(p,cnt);
    }
    cmp[x]=cnt;
}
 
int main()
{
    int n,m;
    cin>>n>>m;
    g.resize(n);
    rg.resize(n);
    used.resize(n);
    cmp.resize(n,0);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
 
    rep(i,n){
        if(!used[i])dfs(i);
    }
    used.assign(n,false);
    int cnt = 0;
	reverse(all(order));
    for(auto x:order){
        if(!used[x]){
            rdfs(x,cnt);
            cnt++;
        }
    }
 
    int q;
    cin>>q;
    rep(i,q){
        int a,b;
        cin>>a>>b;
         
        cout<<(cmp[a]==cmp[b]?1:0)<<endl;
    }
    return 0;
}