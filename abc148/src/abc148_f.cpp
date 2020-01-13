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



int main()
{
    int n,aoki,takahashi;
    cin>>n>>takahashi>>aoki;
    aoki--,takahashi--;
    vector<vector<int>> g(n,vector<int>());
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dist_aoki(n,-1),dist_taka(n,-1);
    
    dist_aoki[aoki] = 0;
    dist_taka[takahashi] = 0;
   queue<int> que;

   que.push(aoki);
   while(!que.empty()){
       int node = que.front();
       que.pop();
       for(auto x: g[node]){
           if(dist_aoki[x]<0){
               dist_aoki[x] = dist_aoki[node]+1;
               que.push(x);
           }
       }
   }
   que.push(takahashi);
   while(!que.empty()){
       int node = que.front();
       que.pop();
       for(auto x: g[node]){
           if(dist_taka[x]<0){
               dist_taka[x] = dist_taka[node]+1;
               que.push(x);
           }
       }
   }

    int ans = 0;
    rep(i,n){
        // cout<<dist_taka[i]<<" "<<dist_aoki[i]<<endl;

        if(dist_aoki[i]>dist_taka[i])ans = max(ans,dist_aoki[i]);
    }
    cout<<ans-1<<endl;

	return 0;
}