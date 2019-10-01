	#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	ll h,w,t;
	cin>>h>>w>>t;
	vector<string> s(h);
	rep(i,h)cin>>s[i];

	ll high=1e9,low=1;
	while(high>low+1){
		ll mid=(high+low)/2;
		priority_queue<P> que;
		vector<vector<ll>> dist(h,vector<ll>(w,INF*INF));
		P start;
		rep(i,h){
			rep(j,w){
				if(s[i][j]=='S')start.first=i,start.second=j;
			}
		}

		que.push(P(0,start.first*w+start.second));

		while(!que.empty()){
			P now=que.top();que.pop();
			ll now_dist=now.first;
			int i=now.second/w;
			int j=now.second%w;

			for (int k = 0; k < 4; k++){
				int next_i=i+dy[k];
				int next_j=j+dx[k];
				if(0<=next_i&&next_i<h&&0<=next_j&&next_j<w){
					ll next_dist=now_dist;
					if(s[next_i][next_j]=='#') next_dist+=mid;
					else next_dist+=1;

					if(dist[next_i][next_j]<next_dist) continue;
					dist[next_i][next_j]=next_dist;

					que.push(P(next_dist,next_i*w+next_j));
				}
			}
		}

		ll time=0;
		rep(i,h){
			rep(j,w){
				if(s[i][j]=='G')time=dist[i][j];
			}
		}
		// cout<<time<<endl;
		if(time<=t) low=mid;
		else high=mid;
	}
	cout<<low<<endl;
	return 0;
}