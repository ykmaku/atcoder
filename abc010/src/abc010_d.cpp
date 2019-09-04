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

struct dinic{
 
    struct edge{
        int to,cap,rev;
        edge(){}
        edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
    };
 
    int n;
    vector<vector<edge> > G;
    vector<int> level;
    vector<int> iter;
 
    dinic(){};
    dinic(int V):n(V),G(n),level(n),iter(n){}
 
    void add_edge(int from,int to,int cap){
        G[from].push_back(edge(to,cap,(int)G[to].size()));
        G[to].push_back(edge(from,0,(int)G[from].size()-1));
    }
 
    //sからの層グラフつくり
    void bfs(int s){
        level.assign(level.size(),-1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int i = 0; i < (int)G[v].size(); i++){
                edge e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v]+1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int v,int t,int f){
        if(v == t) return f;
        for(int &i = iter[v]; i < (int)G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                int d = dfs(e.to,t,min(f,e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s,int t,int lim){
        int flow = 0;
        for(; ;){
            bfs(s);
            if(level[t] < 0 || lim == 0){
                return flow;
            }
            iter.assign(iter.size(),0);
            int f;
            while((f = dfs(s,t,INF)) > 0){
                flow += f;
                lim -= f;
            }
        }
    }
};

int main()
{

	return 0;
}