#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>
 
using namespace std;
 
#define all(x) x.begin(),x.end()
int INF = 1e9;
 
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

int main(){
    int V,E;
    cin >> V >> E;

    dinic din(V);
    for(int i = 0; i < E; i++){
        int u,v,c;
        cin >> u >> v >> c;
        din.add_edge(u,v,c);
    }

    cout << din.max_flow(0,V-1,INF) << endl;
}

//AOJ GRL_6_A