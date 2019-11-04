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

// typedef struct Line{
// 	int l,r,idx;
// 	Line(int l,int r,int idx):l(l),r(r),idx(idx){};
// 	Line(){l=0,r=0,idx=0;};
// 	bool operator<(const Line &line) const{
//         return l < line.l;
//     }
// }Line;
typedef tuple<int,int,int> Line;

int main()
{
	int n;
	cin>>n;
	vector<Line> line(n);
	rep(i,n){
		int l,r;
		cin>>l>>r;
		line[i]=make_tuple(l,r,i);
	}

	sort(all(line));

	set<P> LeftLSet,LeftRSet,RightLSet,RightRSet;

	LeftLSet.insert(P(get<0>(line[0]),get<2>(line[0])));
	LeftRSet.insert(P(get<1>(line[0]),get<2>(line[0])));

	repi(i,1,n){
		RightLSet.insert(P(get<0>(line[i]),get<2>(line[i])));
		RightRSet.insert(P(get<1>(line[i]),get<2>(line[i])));
	}
	int ans=0;
	//cout<<"LeftRSet = "<<LeftRSet.begin()->first<<" LeftLset = "<<LeftLSet.rbegin()->first<<endl;
	//cout<<"RightRSet = "<<RightRSet.begin()->first<<" rightLset = "<<RightLSet.rbegin()->first<<endl;
	int Llength=max(0,LeftRSet.begin()->first-LeftLSet.rbegin()->first+1);
	int Rlength=max(0,RightRSet.begin()->first-RightLSet.rbegin()->first+1);
	ans=Llength+Rlength;

	repi(i,1,n-1){
		// cout<<ans<<endl;
		RightLSet.erase(P(get<0>(line[i]),get<2>(line[i])));
		RightRSet.erase(P(get<1>(line[i]),get<2>(line[i])));

		LeftLSet.insert(P(get<0>(line[i]),get<2>(line[i])));
		LeftRSet.insert(P(get<1>(line[i]),get<2>(line[i])));

		Llength=max(0,LeftRSet.begin()->first-LeftLSet.rbegin()->first+1);
		Rlength=max(0,RightRSet.begin()->first-RightLSet.rbegin()->first+1);
		int res=max(0,Llength+Rlength);
		ans=max(ans,res);
	}

	RightLSet.erase(P(get<0>(line[n-1]),get<2>(line[n-1])));
	RightRSet.erase(P(get<1>(line[n-1]),get<2>(line[n-1])));
	LeftLSet.insert(P(get<0>(line[n-1]),get<2>(line[n-1])));
	LeftRSet.insert(P(get<1>(line[n-1]),get<2>(line[n-1])));

	rep(i,n){
		LeftLSet.erase(P(get<0>(line[i]),get<2>(line[i])));
		LeftRSet.erase(P(get<1>(line[i]),get<2>(line[i])));

		Llength=max(0,LeftRSet.begin()->first-LeftLSet.rbegin()->first+1);
		ans = max(ans,get<1>(line[i])-get<0>(line[i])+1 + Llength);

		LeftLSet.insert(P(get<0>(line[i]),get<2>(line[i])));
		LeftRSet.insert(P(get<1>(line[i]),get<2>(line[i])));
	}


	cout<<ans<<endl;

	return 0;
}