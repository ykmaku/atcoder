#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

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
	int n;
	cin>>n;

	int dist=0,node1=1,node2=0;
	repi(i,2,n+1){
		int d;
		cout<<"?"<<1<<" "<<i<<endl;
		cin>>d;
		if(d>dist){
			dist=d;
			node1=i;
		}
	}
	dist=0;
	repi(i,1,n+1){
		int d;
		cout<<"?"<<node1<<" "<<i<<endl;
		cin>>d;
		if(d>dist){
			dist=d;
			node2=d;
		}
	}
	cout<<"! "<<dist<<endl;

	return 0;
}